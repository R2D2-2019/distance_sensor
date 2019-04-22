#include <mock_usart.hpp>

namespace r2d2 {
    void mock_usart_c::enable() {
        // Not needed in test implementation
    }

    void mock_usart_c::disable() {
        // Not needed in test implementation
    }

    bool mock_usart_c::send(const uint8_t c) {
        return true;
        // Not needed in this test implementation
    }

    void mock_usart_c::putc(char c) {
        send(c);
    }

    uint8_t mock_usart_c::receive() {
        if (char_available()) {
            uint8_t result = receive_buffer[receive_counter];
            receive_counter++;
            return result;
        }
        return 0;
    }

    bool mock_usart_c::char_available() {
        return available() > 0;
    }

    char mock_usart_c::getc() {
        return receive();
    }

    unsigned int mock_usart_c::available() {
        return receive_buffer.size() - receive_counter;
    }

    void mock_usart_c::prepare_message(const std::vector<uint8_t> &message) {
        receive_buffer.clear();
        for (const uint8_t &b : message) {
            receive_buffer.push_back(b);
        }
    }
}; // namespace r2d2
