#ifndef BRAINIAC_SERVER_CONFIG_HPP
#define BRAINIAC_SERVER_CONFIG_HPP

#include <brainiac/ConfigHint.hpp>
#include <boost/json.hpp>

namespace brainiac {

class ServerConfig
{
public:
    ServerConfig();

    template<typename ConfigValue>
    void set(config_hint hint, const ConfigValue& value)
    {
        config_[hint] = value;
    }

    template<typename ConfigValue>
    void set(config_hint hint, ConfigValue&& value)
    {
        config_[hint] = std::forward<ConfigValue>(value);
    }

    template<typename ConfigValue>
    std::optional<ConfigValue> get(config_hint hint) const
    {
    }

private:
    using config_value = std::variant<
        std::size_t
    >;

    std::unordered_map<config_hint, config_value> config_;
};

} // namespace brainiac

#endif // BRAINIAC_SERVER_CONFIG_HPP
