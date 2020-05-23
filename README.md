# Chat

Chat is one app which try to implement the C/S archecture.
Chat is based on the websocket as the message channel which makes the coding simple.
Right now, This is just a scrach project which just begin.
By now, the server side first version finished--just with the feature of text-based streaming. for test reason implement one python version cient which test the server side.

## Software looks below

![demo](./images/demo.png)

## Description

## embeded tech

* websocket

    come to this time, when I check more options for C++ version of websocket, there exist boost.beast
    except the websocketpp, but seems boost version is not easy to understand. But, I inisit to learn
    it with patience.

    current version is written in websocketpp, may be one ay re-write it in boost.

* cmake

    apparently, this is cmake project.

* gtest

    introduce ut with gtest.

* emake https://github.com/skywind3000/emake

    seems this compile method is more simpler than cmake, just need include main.mak, not update the main.mak in time.

* consider add the support of protocal buf of google

* spdlog https://github.com/gabime/spdlog

    with spdlog to logging the log of project

## Hope for myself

## I hope I will insist on this project, which can be one behalf project of mine
