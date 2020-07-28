#include <iostream>
#include <thread>

#include "can_data.h"
#include "can_receiver.h"
#include "websocket_handler.h"

using std::chrono_literals::operator""ms;

int main()
{
    std::setbuf(stdout, NULL);

    if (!WebSocketHandler::CheckJavaScriptConnection())
    {
        std::cerr << "No connection to website possible, closing program!" << '\n';
        return 0;
    }

    CanDataReceiver can_data_receiver{};
    can_data_receiver.OpenCanSocket("vcan0");
    can_data_receiver.AddCanFilter(0x42A, 0x7FF);

    CanData can_data{};

    std::thread update_can_data([&]() { while (true) { can_data.SetData(can_data_receiver.ReadCanData()); }});
    std::thread update_javascript_inputs(WebSocketHandler::GetJavaScriptInputs);

    while (true)
    {
        if (WebSocketHandler::GetStringBuffer().size() > 0)
        {
            std::cout << "Javascript data received: " << WebSocketHandler::GetStringBuffer() << '\n';
            WebSocketHandler::ClearStringBuffer();
        }
        std::cout << can_data.GetVelocity() << '\n';
        std::this_thread::sleep_for(100ms);
    }

    can_data_receiver.CloseSocket();

    update_can_data.join();
    update_javascript_inputs.join();

    return 0;
}