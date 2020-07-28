#include <string>

class WebSocketHandler
{
  public:
    static bool CheckJavaScriptConnection();
    static void GetJavaScriptInputs();
    static std::string& GetStringBuffer();
    static void ClearStringBuffer();

  private:
    static bool is_connected_;
    static std::string string_buf_;
};