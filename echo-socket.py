import socketserver

class RequestHandler (socketserver.BaseRequestHandler):
    def handle(self):
        self.data = self.request.recv(1024).strip()
        print("Received: ", self.data)

if __name__ == '__main__':
    HOST, PORT = "localhost", 58790

    with socketserver.TCPServer((HOST, PORT), RequestHandler) as server:
        server.serve_forever()
