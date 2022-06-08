// 模板与继承
// Created by Percy on 2022/6/8.
//

// 模板实参的缺省使得我们在调整第N个实参时，还得指定前N-1个
// 但相比 BreadSlicer<DefaultPolicy1, DefaultPolicy2, Custom> 我们更倾向于 BreadSlicer<Policy3=Custom>

// 因此可以设法把缺省类型值放到一个基类中，再通过派生来覆盖掉一些类型值

class DefaultPolicies {
public:
    typedef DefaultPolicy1 P1;
    typedef DefaultPolicy2 P2;
    typedef DefaultPolicy3 P3;
    typedef DefaultPolicy4 P4;
};

class DefaultPolicyArgs : virtual public DefaultPolicies {};

template <typename PolicySetter1 = DefaultPolicyArgs,
    typename PolicySetter2 = DefaultPolicyArgs,
    typename PolicySetter3 = DefaultPolicyArgs,
    typename PolicySetter4 = DefaultPolicyArgs>
class BreadSlicer {
    typedef PolicySelector<PolicySetter1, PolicySetter2, PolicySetter3, PolicySetter4> Policies;
};

template <typename Base, int D>
class Discriminator : public Base {};

template <typename Setter1, typename Setter2, typename Setter3, typename Setter4>
class PolicySelector : public Discriminator<Setter1, 1>,
                       public Discriminator<Setter2, 2>,
                       public Discriminator<Setter3, 3>,
                       public Discriminator<Setter4, 4> {};
