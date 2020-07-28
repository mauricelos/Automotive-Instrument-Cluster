#include <chrono>
#include <iostream>
#include <thread>

#include "websocket_handler.h"

using std::chrono_literals::operator""ms;

bool WebSocketHandler::CheckJavaScriptConnection()
{
    std::string connection_status{};
    std::cin >> connection_status;

    is_connected_ = connection_status == "Connected" ? true : false;

    return connection_status == "Connected" ? true : false;
}

void WebSocketHandler::GetJavaScriptInputs()
{
    while (is_connected_)
    {
        std::string temp_buf{};
        std::cin >> temp_buf;
        string_buf_ += temp_buf;
        std::this_thread::sleep_for(100ms);
    }
}

std::string& WebSocketHandler::GetStringBuffer()
{
    return string_buf_;
}

void WebSocketHandler::ClearStringBuffer()
{
    string_buf_.clear();
}

bool WebSocketHandler::is_connected_ = false;
std::string WebSocketHandler::string_buf_ = {};
