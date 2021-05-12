/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: ServerStub
 * Author: lvyingchao 00596108
 * Create: 2021-05-11
 */
//
// Created by l00596108 on 2021/5/11.
//

#ifndef MYRPC_SERVERSTUB_H
#define MYRPC_SERVERSTUB_H

#include <fstream>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


#include "errorCodes.h"
#include "server_infos.h"
#include "protobufs.pb.h"
#include "structs_define.h"


class ServerStub {
public:
    ServerStub() = default;
    ~ServerStub() = default;
    ServerStub(const ServerStub &) = default;
    ServerStub &operator=(const ServerStub &) = default;

    int go()
    {
        int    socket_fd, connect_fd;
        struct sockaddr_in servaddr;
        int     n;
        //初始化Socket
        if( (socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ){
            printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
            exit(0);
        }

        //初始化
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址。
        servaddr.sin_port = htons(7777);//设置的端口为DEFAULT_PORT

        //将本地地址绑定到所创建的套接字上
        if( bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
            printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
            exit(0);
        }
        //开始监听是否有客户端连接
        if( listen(socket_fd, 10) == -1){
            printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
            exit(0);
        }

        while(1){
//阻塞直到有客户端连接，不然多浪费CPU资源。
            if( (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)) == -1){
                printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
                continue;
            }
            protobufs::remoteAdd remoteAddPara;
            size_t paraLength = 4;
            char* buff = new char[paraLength];
//            char    buff[4096];
//接受客户端传过来的数据
            n = recv(connect_fd, buff, paraLength, 0);


            std::string inputBufferStr(buff, paraLength);
            remoteAddPara.ParseFromString(inputBufferStr);
            AddPara addPara{remoteAddPara.para1(), remoteAddPara.para2()};
            std::cout << remoteAddPara.para1() << std::endl;
            std::cout << remoteAddPara.para2() << std::endl;

            AddReturn addReturn = add(addPara);
            protobufs::remoteReturn remoteAddResult;
            remoteAddResult.set_ans(addReturn.ans);
//            std::cout << remoteAddResult.ans() << std::endl;
            const char* resultBuffer = remoteAddResult.SerializeAsString().c_str();
            size_t resultLength = remoteAddResult.ByteSizeLong();
//            std::cout << resultLength << std::endl;

//向客户端发送回应数据
            if(!fork()){ /*紫禁城*/
                if(send(connect_fd, resultBuffer, resultLength,0) == -1)
                    perror("send error");
                delete[] buff;
                close(connect_fd);
                exit(0);
            }
            printf("recv msg from client: \n");
            delete[] buff;
            close(connect_fd);
        }
        close(socket_fd);
    }

private:
//    template <typename ParaType, typename std::enable_if<std::is_pod<ParaType>::value>::type* = nullptr>
//    void Parse(ParaType& para, const char* const buffer, size_t length)
//    {
//        memcpy_s(para, length, buffer, length);
//    }
//
//    template <typename ParaType, typename std::enable_if<std::is_pod<ParaType>::value>::type* = nullptr>
//    void Serialize(const ParaType& para, char* buffer, size_t length)
//    {
//        memcpy_s(buffer, length, para, length);
//    }

    AddReturn add(const AddPara& addPara)
    {
        return {addPara.para1 + addPara.para2};
//        return {4};
    }
};


#endif //MYRPC_SERVERSTUB_H
