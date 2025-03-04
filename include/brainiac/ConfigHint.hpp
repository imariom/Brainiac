#ifndef BRAINIAC_CONFIG_HINT_HPP
#define BRAINIAC_CONFIG_HINT_HPP

namespace brainiac {

enum class config_hint : unsigned short
{
    unknown = 0,

    port,
    host,
    timeout,
    max_connections,

    cache_size,
    cache_ttl,
};

} // namespace brainiac

#endif // BRAINIAC_CONFIG_HINT_HPP
