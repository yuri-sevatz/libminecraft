#include "remote.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            Remote::Remote(const std::string &hostname,
                                         const std::string &service) : Session(/*_world,*/ _self),
            // Connection attributes.
            stream(hostname, service),
            proto(stream),
            fsm(*this)/*,
            gz_data(std::ios_base::out | std::ios_base::in | std::ios_base::binary) */
            {

            }

            void Remote::connect(const std::string &username, const std::string &key)
            {
                this->username = username;

                fsm.ChangeState(fsm.States.CONNECTING);

                // Enter the master loop...
                loop();
            }

            void Remote::disconnect()
            {
                fsm.ChangeState(fsm.States.DISCONNECTED);
            }

            void Remote::loop()
            {
                try
                {
                    while(true)
                        fsm.Update();
                }
                catch (libminecraft::Exception ex)
                {
                    /* listener().onNetworkError(ex.message); */
                    std::cerr << ex.what() << std::endl;
                    disconnect(); // Kill the game.
                }
            }
        }
    }
}
