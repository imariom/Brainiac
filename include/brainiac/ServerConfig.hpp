#ifndef BRAINIAC_SERVER_CONFIG_HPP
#define BRAINIAC_SERVER_CONFIG_HPP

#include <brainiac/Config.hpp>
#include <brainiac/ConfigHint.hpp>
#include <boost/json.hpp>

namespace brainiac {

class ServerConfig
{
public:
    ServerConfig();

    template<typename ConfigValue>
    void set(ConfigHint hint, const ConfigValue& value)
    {
        config_[hint] = value;
    }

    template<typename ConfigValue>
    void set(ConfigHint hint, ConfigValue&& value)
    {
        config_[hint] = std::forward<ConfigValue>(value);
    }

    template<typename ConfigValue>
    std::optional<ConfigValue> get(ConfigHint hint) const
    {
    }

private:
    using config_value = std::variant<
        std::int64_t,
        boost::json::string
    >;

    std::unordered_map<ConfigHint, config_value> config_;
};

} // namespace brainiac

#endif // BRAINIAC_SERVER_CONFIG_HPP
