#ifndef BRAINIAC_SERVER_CONFIG_HPP
#define BRAINIAC_SERVER_CONFIG_HPP

#include <brainiac/Config.hpp>
#include <brainiac/ConfigHint.hpp>
#include <boost/json.hpp>

#include <optional>
#include <variant>

namespace brainiac {

class ServerConfig
{
    using ConfigValue = std::variant<
        std::int64_t,
        boost::json::string
    >;

public:
    ServerConfig();

    template<typename Value>
    std::optional<Value> get(ConfigHint hint) const
    {
        ConfigValue value = config_.at(hint);
        if (std::holds_alternative<Value>(value))
        {
            return std::optional(std::get<Value>(value));
        }
        return std::nullopt;
    }

private:
    std::unordered_map<ConfigHint, ConfigValue> config_;
};

} // namespace brainiac

#endif // BRAINIAC_SERVER_CONFIG_HPP
