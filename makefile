all:
	gcc -o client test_client.c
	gcc -o server test_server.c
	gcc -o c client_socket_test.c
	gcc -o s server_socket_test.c
