# FCFS___SJF
先来先服务FCFS和短作业优先SJF进程调度算法
### 实现算法

FCS：（choose1）

1.根据给出的ARRIveTime 和ServiceTime 分别算出i所对应的Finishtime，WeighTime，WholeTime.Starttime 并将各项打印出来.

2.调用函数Check（0） 若 时间t 内进程p 在 StartTime 和finishTime 之间

则输出运行，否则则 输出不运行。从而显示每时刻进程运行状况。

SJF：（choose）

1.先根据servicetime排序 得到ServiceNum；即服务为顺序

根据给出的ARRIveTime 和ServiceTime，serviceNum 分别算出i所对应的Finishtime ,Starttime WeighTime，WholeTime.Starttime ,并且打印各项

2.调用函数Check（0） 若 时间t 内进程p 在 StartTime 和finishTime 之间

则输出运行，否则则 输出不运行。从而显示每时刻进程运行状况。

#### 以上算法均由数组实现

### 运行效果截图
-FCTS

![Image](https://github.com/tomridder/FCFS___SJF/blob/master/%E5%9B%BE%E7%89%871.png)

-SJF
![Image](https://github.com/tomridder/FCFS___SJF/blob/master/%E5%9B%BE%E7%89%872.png)

