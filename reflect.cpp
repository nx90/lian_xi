//
// Created by l84141518 on 2019/10/18.
//

#include <basetsd.h>
#include <map>
#include <cstdio>
#include <iostream>
#include "typeinfo"

// NEDC公共phyPort
struct PceNeDcPhyPort {
    UINT16 shelf;       // 子架
    UINT8 board;       // 单板
    UINT64 nima;
};

struct PceCommissionDotInfo {
    PceNeDcPhyPort phyPort;
    UINT32 adjustPtType;              // 调节点类型，1：WSS EVOA 调节点/EVOA 合波调节点  2：OA 增益
    UINT32 adjustPtNum;               // 调节点数量，当调节点类型取值为2或3时，调节点数量为1
};

struct PceNelinkLinkBase {
    PceNeDcPhyPort remoteKey;          // 远端节点和链路索引
    PceCommissionDotInfo phyPort;              // 物理端口
};

#define REFLECT_CLASS_HEAD(type)    \
class _##type##_helper{             \


class A{
public:
    explicit A(PceNeDcPhyPort& p) : pp{p} {}
    ~A() = default;

    virtual UINT16 get1() { return pp.shelf;}
    virtual UINT8 get2() { return pp.board;}
    virtual UINT64 get3() { return pp.nima;}
    PceNeDcPhyPort pp;
};

template <typename T>
void cc(T& b){
    //Base b;
    typedef UINT16 (*FUNC)(void);
    typedef UINT8 (*FUNC1)(void);
    typedef UINT64 (*FUNC2)(void);

    // 对象b的地址
    int *bAddress = (int *)&b;

    // 对象b的vtptr的值
    int *vtptr = (int *)*(bAddress + 0);
    std::printf("vtptr: 0x%08x\n", vtptr);

    // 对象b的第一个虚函数的地址
    int *pFunc1 = (int *)*(vtptr + 0);
    int *pFunc2 = (int *)*(vtptr + 1);
    int *pFunc3 = (int *)*(vtptr + 2);
    printf("\t vfunc1addr: 0x%08x \n"
           "\t vfunc2addr: 0x%08x \n"
           "\t vfunc3addr: 0x%08x \n",
           pFunc1,
           pFunc2,
           pFunc3);

    // 对象b的两个成员变量的值（用这种方式可轻松突破private不能访问的限制）
    int mem1 = (int)*(bAddress + 1);
    int mem2 = (int)*(bAddress + 2);
    printf("m_iMem1: %d \nm_iMem2: %d \n\n",mem1, mem2);

    // 调用虚函数
    std::cout << (FUNC(pFunc1))() << std::endl;
    std::cout << (FUNC1(pFunc2))() << std::endl;
    std::cout << (FUNC2(pFunc3))() << std::endl;

}
/*
const std::map<std::type_info, A> helperMap = {
    {typeid(std::declval<PceNeDcPhyPort>()), std::declval<A>()},
};


void b(PceNeDcPhyPort lv){
    auto it = helperMap.find(typeid(lv));
    decltype(it->second) a{lv};
    a.get1();
    a.get2();
}

*/

int main() {
    PceNeDcPhyPort lv{8,9,11};
    A a(lv);
    cc(a);
    return 0;
}




