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

    printf("[FIREWALL] RAW SOCKET PORT FILTER STARTED\n");

    while (1) {
        socklen_t saddr_size = sizeof(saddr);
        int size = recvfrom(sock, buffer, sizeof(buffer), 0,
                            &saddr, &saddr_size);
        if (size < 0) {
            perror("recvfrom failed");
            break;
        }

        ip = (struct iphdr *)buffer;

        struct in_addr src, dst;
        src.s_addr = ip->saddr;
        dst.s_addr = ip->daddr;

        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        strcpy(src_ip, inet_ntoa(src));
        strcpy(dst_ip, inet_ntoa(dst));

        /* ===== TCP ===== */
        if (ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp =
                (struct tcphdr *)(buffer + ip->ihl * 4);

            int sport = ntohs(tcp->source);
            int dport = ntohs(tcp->dest);

            if (is_blocked_port(dport)) {
                printf("[BLOCK][TCP] %s:%d -> %s:%d\n",
                       src_ip, sport, dst_ip, dport);
                continue; // DROP (logic)
            }

            printf("[ALLOW][TCP] %s:%d -> %s:%d\n",
                   src_ip, sport, dst_ip, dport);
        }

        /* ===== UDP ===== */
        else if (ip->protocol == IPPROTO_UDP) {
            struct udphdr *udp =
                (struct udphdr *)(buffer + ip->ihl * 4);

            int sport = ntohs(udp->source);
            int dport = ntohs(udp->dest);

            if (is_blocked_port(dport)) {
                printf("[BLOCK][UDP] %s:%d -> %s:%d\n",
                       src_ip, sport, dst_ip, dport);
                continue;
            }

            printf("[ALLOW][UDP] %s:%d -> %s:%d\n",
                   src_ip, sport, dst_ip, dport);
        }
    }

    close(sock);
    return 0;
}
