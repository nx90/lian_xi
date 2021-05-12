//
// Created by may on 2021/5/10.
//

#ifndef MYRPC_CLIENTSTUB_H
#define MYRPC_CLIENTSTUB_H

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

using std::string;



class ClientStub {
public:
    ClientStub() = default;
    ~ClientStub() = default;
    ClientStub(const ClientStub&) = default;
    ClientStub& operator=(const ClientStub&) = default;
//public:
//    ClientStub(const ClientStub&) = delete;
//    ClientStub& operator=(const ClientStub&) = delete;
//    static ClientStub& getInstance()
//    {
//        static ClientStub instance;
//        return instance;
//    }

    template <typename ReturnType, typename ...ParaTypes>
    int call(const string& funcName, ReturnType& returnValue, const ParaTypes& ...paras)
    {
        string serverName = funcName.substr(0, funcName.find('.'));
        auto iter = serverAddrs.find(serverName);
        if (iter == serverAddrs.end()) {
            return CALL_NO_SUCH_SERVER;
        }
        struct sockaddr_in serverAddr = iter->second;
        protobufs::remoteAdd remoteAddPara;
        AddPara addPara{paras...};
        remoteAddPara.set_para1(addPara.para1);     // 后面看来要改成 ParseFromCodedStream 方式构造
        remoteAddPara.set_para2(addPara.para2);

        int    socket_fd;

        //初始化Socket
        if( (socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ) {
            printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
            exit(0);
        }
        //初始化
//        memset(&serverAddr, 0, sizeof(serverAddr));
//        serverAddr.sin_family = AF_INET;
//        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址。
//        serverAddr.sin_port = htons(7777);//设置的端口为DEFAULT_PORT

        if (connect(socket_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        {
            perror("connect");
            exit(1);
        }

        // socket 上写东西
        const char* myInput = remoteAddPara.SerializeAsString().c_str();
        size_t paraLength = remoteAddPara.ByteSizeLong();

        if( send(socket_fd, myInput, paraLength, 0) < 0)
        {
            printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
            exit(0);
        }


        protobufs::remoteReturn remoteAddResult;
        size_t resultLength = 2;
        char* resultBuffer = new char[resultLength];
        if((recv(socket_fd, resultBuffer, resultLength,0)) == -1) {
            perror("recv error");
            exit(1);
        }

        string resultStr(resultBuffer, resultLength);
        remoteAddResult.ParseFromString(resultStr);
        returnValue.ans = remoteAddResult.ans();
//        std::cout << remoteAddResult.ans() << std::endl;

        delete[] resultBuffer;
        close(socket_fd);

    }

private:
//    template <typename ParaType, typename std::enable_if<std::is_pod<ParaType>::value>::type* = nullptr>
//    void Parse(ParaType& para, const char* const buffer, size_t length)
//    {
//        memcpy_s(para, length, buffer, length);
//    }

};


#endif //MYRPC_CLIENTSTUB_H
