# ObjectPool-cocos2d-x

**面向cocos2dx的对象池**

1.ObjectPool是一个cocos2d-x的对象池模版基类。

2.继承于ObjectPool可以实现不同cocos2d-x类型的对象池，这里实现了一个精灵类型的对象池SpritePool。

3.这里的对象池并不只是cocos2d-x底层的引用计数对象池，是基于底层引用计数的封装，放在对象池里的对象保留了所有属性及占用内存。

4.在lua中使用该对象池需要进行lua－binding，这里给出已生成的绑定文件。

5.可以对其扩展，继承于ObjectPool的其他cocos2d-x类型的对象池，SpritePool只是抛砖引玉。

