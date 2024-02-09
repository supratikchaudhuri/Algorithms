def myNormalizer(url):
    default_protocol = "http"
    default_domain = "localhost"
    default_port = "80"
    default_path = "/"

    if url == "":
        return f"{default_protocol}://{default_domain}:{default_port}{default_path}"

    parts = url.split("://")
    protocol, remainder = parts

    if protocol == "":
        protocol = default_protocol
    
    domain_parts = remainder.split(":")
    domain, remainder = domain_parts

    if domain == "":
        domain = default_domain
    
    port_parts = remainder.split("/")
    port, remainder = port_parts

    if port == "":
        port = default_port

    path = remainder

    if path == "":
        path = default_path

    normalized_url = f"{protocol}://{domain}:{port}/{path}"
    return normalized_url