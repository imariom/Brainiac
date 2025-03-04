#include <brainiac/ProxyServer.hpp>

int main(int argc, char* argv[])
{
    brainiac::ProxyServer server;
    server.run();
    return EXIT_SUCCESS;
}

