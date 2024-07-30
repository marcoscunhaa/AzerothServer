#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Criar um endpoint TCP para escutar na porta 12345
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
        std::cout << "Servidor escutando na porta 12345..." << std::endl;

        // Esperar por uma conexão
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "Cliente conectado!" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exceção: " << e.what() << std::endl;
    }

    return 0;
}
