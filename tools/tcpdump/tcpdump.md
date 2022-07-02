

# tcpdump -i <interface> "tcp[tcpflags] & (tcp-syn) != 0"
只捕获TCP ACK包：

# tcpdump -i <interface> "tcp[tcpflags] & (tcp-ack) != 0"
只捕获TCP FIN包：

# tcpdump -i <interface> "tcp[tcpflags] & (tcp-fin) != 0"
之捕获TCP SYN或ACK包：

# tcpdump -r <interface> "tcp[tcpflags] & (tcp-syn|tcp-ack) != 0"