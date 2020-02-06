一、矩阵掩膜

1、重要函数
1.获取图像像素指针
Mat src;
src.ptr<uchar>(i) 获取图像像素的指针，i表示第i行

2.通道数
src.channels()

3.位图深度
src.depth()，有如下值
CV_8U - 8-bit unsigned integers ( 0..255 )
CV_8S - 8-bit signed integers ( -128..127 )
CV_16U - 16-bit unsigned integers ( 0..65535 )
CV_16S - 16-bit signed integers ( -32768..32767 )
CV_32S - 32-bit signed integers ( -2147483648..2147483647 )
CV_32F - 32-bit floating-point numbers ( -FLT_MAX..FLT_MAX, INF, NAN ) 
CV_64F - 64-bit floating-point numbers ( -DBL_MAX..DBL_MAX, INF, NAN )


2、像素范围处理
saturate_cast<uchar>(-100) 返回0 
saturate_cast<uchar>(100)	 返回100
saturate_cast<uchar>(288)  返回255

3、公式
矩阵的掩膜操作十分简单，就是掩膜来计算每个像素的像素值，从而提升对比度，掩膜（mask也被称作kernel）
I(i,j) = 5*I(i,j)-[I(i+1,j)+I(i-1,j)+I(i,j+1)+I(i,j-1)]

-          -
| 0  -1  0 |
| -1  5  -1|
| 0  -1  0 |
-					 -
红色是中心像素，从上到下，从左到右，对每个像素做同样的处理操作，得到最终结果就是对比度提高之后的输出图像的mat对象

示例：TestKernel
示例1：
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = Mat(src.size(), src.type());//type包含深度（depth）和通道数（channel）
imshow("test1",src);
int rows = src.rows;
int cols = src.cols*src.channels();
int xoffset = src.channels();

for(int i = 1;i < rows-1;i++)//上下两行不计算
{
    uchar* current = src.ptr<uchar>(i);
    uchar* pre = src.ptr<uchar>(i-1);
    uchar* next = src.ptr<uchar>(i+1);
    uchar* dstptr = dst.ptr<uchar>(i);
	
    for(int j = xoffset;j < cols-xoffset;j++)//左右两列不计算
    {
        dstptr[j] = saturate_cast<uchar>(5*current[j] - (pre[j]+next[j]+current[j+xoffset]+current[j-xoffset]));
	
   }
}  
imshow("test2",dst);

saturate_cast<uchar> 不加有麻点，加入限制范围在0-255之间
对比度提高 感官更强烈


示例2：
/*Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = Mat(src.size(), src.type());
imshow("test1",src);
int rows = src.rows; 
int cols = src.cols;//src.size().width*src.channels();src.cols*src.channels();
cout<<src.channels()<<endl;
for(int i = 1;i < rows-1;i++)
{
    uchar(*current)[3] = src.ptr<uchar[3]>(i);
    uchar(*pre)[3] = src.ptr<uchar[3]>(i-1);
    uchar(*next)[3] = src.ptr<uchar[3]>(i+1);
    uchar(*dstptr)[3] = dst.ptr<uchar[3]>(i);
    for(int j = 1;j < cols-1;j++)
    {
        for(int k = 0;k < 3;k++)
        {
            dstptr[j][k] = saturate_cast<uchar>(5*current[j][k]-(
                                                current[j-1][k]+
                                                current[j+1][k]+
                                                pre[j][k]+
                                                next[j][k]));
        } 
    }
}  
imshow("test2",dst);*/
 Mat src = imread(IMAGE_PATH(shu.jpeg));
            Mat dst = Mat(src.size(),src.type());//包含深度和通道数
            int width= src.size().width*src.channels();//src.cols
            int height = src.size().height;//src.rows
            int offset = src.channels();
            for(int y = 1; y <height-1; y++)//遍历纵坐标 上下两行不计算
            {
                uchar* current = src.ptr<uchar>(y);//当前行
                uchar* per = src.ptr<uchar>(y-1);//上一行
                uchar* next = src.ptr<uchar>(y+1);//当前行
                uchar* dstLine = dst.ptr<uchar>(y);//当前行
                for(int x = offset; x<width-offset; x++)//遍历横左边  左右两行不计算
                {
                    dstLine[x] = saturate_cast<uchar>(
                                current[x]*5 -(
                                    per[x]+next[x]+current[x-offset]+current[x+offset]
                                    )
                                 );
                }

            }

            imshow("src",src);
            imshow("dst",dst);

4、调用filter2D函数
定义掩膜：（克隆）
Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
0 -1 0
-1 5 -1
0 -1 0
filter2D(src, dst, src.depth(), kernel);其中src与dst是Mat类型变量

//filter2D(src, dst, -1, kernel);
示例：
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = Mat(src.size(), src.type());//包含深度和通道数
imshow("test1",src);
Mat kernel = (Mat_<char>(3,3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
filter2D(src, dst, src.depth(), kernel);
imshow("test2",dst);


练习：播放视频，对每一帧图像进行掩膜操作
VideoCapture vc;
if(!vc.open(0))//开启摄像头
{
    qDebug()<<"摄像头打开失败";
}
//namedWindow("掩膜前");
//namedWindow("掩膜后");
while(true)
{
    Mat frame;
    vc>>frame;//读取一帧数据
	 if(!frame.data)
        {
            break;
        }
    Mat dst = Mat(frame.size(), frame.type());
    Mat kernel = (Mat_<char>(3, 3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(frame, dst, frame.depth(), kernel);
    imshow("掩膜前", frame);
    imshow("掩膜后", dst);
    if(waitKey(30)>0)
    {
        break;
    }
	 int k = waitKey(0);
       if(k>='a' && k<= 'z')
       {
          imshow("test",frame);
           imshow("test",dst);
       }
      if(k == 'A')
      {
           break;
       }
}

 

二、Mat对象
1、计算机“眼中”的图片（二维数组）

2、Mat常用操作
1.void copyTo(Mat mat) 复制图像对象
示例：
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst;
src.copyTo(dst);
imshow("test",dst);

    
2.Mat clone()		复制图像对象
示例：
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = src.clone();
imshow("test",dst);

3.void convertTo(Mat dst, int type) 数组转换（KNN算法会用到）
4.int channels()  通道数
5.int type()	返回元素类型，如CV_32FC3
6.int depth()  返回深度（通道中的元素类型，如CV_32F） 
7.bool empty() 判断数组为空 data 
8.uchar* ptr(i=0) 获得i行的指针

3、部分复制和完全复制(深拷贝和浅拷贝)
Mat A = imread(filepath);
Mat B(A);//部分复制  只复制A的数据头和指针部分，不复制数据部分

//完全复制(深拷贝)
clone()和copyTo()


************************************************
画一条黑线，浅拷贝一起变化，深拷贝可单独改变
************************************************
示例：
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst(src);
//Mat dst;
//src.copyTo(dst);
//Mat dst = src.clone();
int cols = src.cols*src.channels();
for(int i = 0;i < 200;i++)
{
    uchar* line = src.ptr<uchar>(i);
    for(int j = 0;j < cols;j++)
    {
        line[j] = 0;
    }
}
imshow("test1", src);
imshow("test2", dst);


4、Mat创建
1)构造函数
Mat m(2, 3, CV_8UC3, Scalar(0, 0, 255));
参数1和参数2分别表示Mat的高度（raw）和宽度（column）
参数3表示数组的类型，CV_{8U,16S,16U,32S,32F,64F}C{1,2,3}
参数4向量表示对每个元素的初始化值，向量的长度和通道数一致

示例：
	Mat src = Mat(400/*高度*/, 500/*宽度*/, CV_8UC3, Scalar(0, 0, 255));
	imshow("test", src);

2)create函数
	Mat m;
    m.create(400/*高度*/,200/*宽度*/,CV_8UC3);
    m = Scalar(127,0,255);
    imshow("src",m);
	cout<<m<<endl;
    //构造
    Mat src= Mat(400,500,CV_8UC3,Scalar(0,0,255));
    imshow("test",src);
m：cout<<m<<endl;
截取三行
[127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,  
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,  
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255,

5、定义小数组
Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);     
cout << "C = " << endl << " " << C << endl;
/*
Mat C = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl;*/

输出结果：
C = 
 [  0,  -1,   0;
  -1,   5,  -1;
   0,  -1,   0]

练习：创建7个100x100的图像并显示，颜色分别是红橙黄绿青蓝紫

Scalar colors[7] = {Scalar(0, 0, 255),
                        Scalar(0, 125, 255),
                        Scalar(0, 255, 255),
                        Scalar(0, 255, 0),
                        Scalar(255, 255, 0),
                        Scalar(255, 0, 0),
                        Scalar(240, 32, 160)
                       };
//char* titles[7] = {"1","2","3","4","5","6","7"};
 string titles[7] = { "1","2","3","4","5","6","7"};
for(int i = 0;i < 7;i++)
{
    Mat color(100, 100, CV_8UC3, colors[i]);
    imshow(titles[i], color);
}