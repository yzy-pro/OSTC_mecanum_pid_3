# 麦轮建模

含有 //@@@ 注释的参数为待测或待实验参数

* 轮子ABCD分别在1234象限
* AB角平分线为x正方向，并且认为此为车“前进”的方向
* BC。。。为y正方向
* 角速度以向上为正方向
* alpha为x正向于AC轮连线夹角 暂时填45
* beta为其余角 暂时填45
* theta为麦轮的辊子和轮子的夹角 暂时填45
* R是单个麦轮到车中心的距离
* 建模参考https://blog.csdn.net/u014453443/article/details/107228531?sharetype=blog&shareId=107228531&sharerefer=APP&sharesource=2403_88153395&sharefrom=qq

# 接线方案
接线参考[mecanum_pid_3.ioc](mecanum_pid_3.ioc)中的引脚名称