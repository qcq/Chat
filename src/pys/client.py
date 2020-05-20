import websocket
try:
    import thread
except ImportError:
    import _thread as thread


def on_message(ws, message):
    print(message)


def on_error(ws, error):
    print(error)


def on_close(ws):
    ws.close()
    print("### closed ###")


def on_open(ws):
    def run(*args):
        while True:
            text = input()
            ws.send('Me: ' + text)
    thread.start_new_thread(run, ())


if __name__ == "__main__":
    #pip3 install websocket_client
    ws = websocket.WebSocketApp("ws://127.0.0.1:7890/index.html?name=lh",
                              on_message = on_message,
                              on_error = on_error,
                              on_close = on_close)
    ws.on_open = on_open
    ws.run_forever()
