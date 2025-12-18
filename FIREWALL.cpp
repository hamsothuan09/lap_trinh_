int main() {
    int sock;
    char buffer[65536];

    struct sockaddr saddr;
    struct iphdr *ip;

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (sock < 0) {
        perror("Socket error");
        return 1;
    }

    printf("[FIREWALL] RAW SOCKET STARTED\n");

    while (1) {
        int data_size = recvfrom(sock, buffer, sizeof(buffer),
                                 0, &saddr, (socklen_t[]){sizeof(saddr)});

        if (data_size < 0) {
            perror("Recv failed");
            break;
        }

        ip = (struct iphdr*)buffer;

        struct in_addr src, dst;
        src.s_addr = ip->saddr;
        dst.s_addr = ip->daddr;

        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];

        strcpy(src_ip, inet_ntoa(src));
        strcpy(dst_ip, inet_ntoa(dst));

        if (is_blocked(src_ip)) {
            printf("[BLOCK] Packet from %s -> %s\n", src_ip, dst_ip);
            continue; // DROP
        }

        printf("[ALLOW] Packet %s -> %s | Protocol %d\n",
               src_ip, dst_ip, ip->protocol);
    }

    close(sock);
    return 0;
}