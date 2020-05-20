#!/usr/bin/env python3
import argparse
import websocket
try:
    import thread
except ImportError:
    import _thread as thread


'''
https://pypi.org/project/websocket_client/
'''


# ANSI colors
c = (
    "\033[0m",   # End of color
    "\033[36m",  # Cyan
    "\033[91m",  # Red
    "\033[35m",  # Magenta
)


def on_message(ws, message):
    print(message + "\033[35m")


def on_error(ws, error):
    print(error)


def on_close(ws):
    ws.close()
    print("### closed ###")

username = ''

def on_open(ws):
    def run(*args):
        while True:
            text = input()
            # try back
            # print('\x08' * len(text))
            if text == 'exit':
                ws.send(username + ":" + text)
                ws.close()
                exit
            ws.send(username + ":" + text)
    thread.start_new_thread(run, ())


def __parser_command_line__():
    parser = argparse.ArgumentParser()
    parser.add_argument("-u", "--username",
                        help="indicate the user name", required=True)
    return parser.parse_args()


if __name__ == "__main__":
    args = __parser_command_line__()
    #pip3 install websocket_client
    ws = websocket.WebSocketApp("ws://127.0.0.1:7890/index.html?name=" + args.username,
                              on_message = on_message,
                              on_error = on_error,
                              on_close = on_close)
    username = args.username
    ws.on_open = on_open
    ws.run_forever()
    print("\033[0m")
