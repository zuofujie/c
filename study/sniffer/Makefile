obj = main.o snf_show_net_info.o

all: $(obj)
	gcc -g -Wall -o sniffer $(obj) -lpcap
main.o: main.c
	gcc -c main.c -lpcap
snf_show_net_info.o: snf_show_net_info.c
	gcc -c snf_show_net_info.c -lpcap
clean:
	rm -rf *.o sniffer
