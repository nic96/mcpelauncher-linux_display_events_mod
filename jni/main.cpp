#include <iostream>


class Entity {
public:
    std::string const& getNameTag() const;
};

class Player: public Entity{};


class TextPacketType{};

namespace minecraft{
    namespace api{
        struct PlayerInterface{
            void handlePlayerJoinedEvent(Player& player) const;
            static void (*$handlePlayerJoinedEvent)(Player& player);
            void $$handlePlayerJoinedEvent(Player& player) const {
                std::cout << player.getNameTag() << " joined the game" << std::endl;
            }
            void handlePlayerLeftEvent(Player& player) const;
            static void (*$handlePlayerLeftEvent)(Player& player);
            void $$handlePlayerLeftEvent(Player& player) const {
                std::cout << player.getNameTag() << " left the game" << std::endl;
            }
        };
        struct NetworkInterface{
            void handleChatEvent(Player* player, TextPacketType, std::string const& message) const;
            static void (*$handleChatEvent)(Player* player, TextPacketType, std::string const& message);
            void $$handleChatEvent(Player* player, TextPacketType, std::string const& message) const {
                std::cout << "<" << player->getNameTag() << "> " << message << std::endl;
            }
        };
    }
}

void (*minecraft::api::PlayerInterface::$handlePlayerJoinedEvent)(Player& player);
void (*minecraft::api::PlayerInterface::$handlePlayerLeftEvent)(Player& player);
void (*minecraft::api::NetworkInterface::$handleChatEvent)(Player* player, TextPacketType, std::string const& message);

extern "C" {

void *mcpelauncher_hook(void* symbol, void* hook, void** original);
void mcpelauncher_unhook(void* hook);

void mod_init() {
    std::cout << "init display_player_events_mod\n";
    mcpelauncher_hook((void*) &minecraft::api::PlayerInterface::handlePlayerJoinedEvent, (void*) &minecraft::api::PlayerInterface::$$handlePlayerJoinedEvent, (void**) &minecraft::api::PlayerInterface::$handlePlayerJoinedEvent);
    mcpelauncher_hook((void*) &minecraft::api::PlayerInterface::handlePlayerLeftEvent, (void*) &minecraft::api::PlayerInterface::$$handlePlayerLeftEvent, (void**) &minecraft::api::PlayerInterface::$handlePlayerLeftEvent);
    mcpelauncher_hook((void*) &minecraft::api::NetworkInterface::handleChatEvent, (void*) &minecraft::api::NetworkInterface::$$handleChatEvent, (void**) &minecraft::api::NetworkInterface::$handleChatEvent);
}

}
