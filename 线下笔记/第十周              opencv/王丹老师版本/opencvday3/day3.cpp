
示例项目：TestMatDay3
一、图像操作
1、读取一个灰度图的像素值
读一个GRAY像素点的像素值（CV_8UC1）
Scalar intensity = img.at<uchar>(y, x); 
或者 Scalar intensity = img.at<uchar>(Point(x, y));

//示例：查看单通道图片 一个像素点的值
Mat src = imread("d:/farsight/opencv/testres/head1.png");
if(src.empty())
    {
        qDebug()<<"load failed";
        return;
    }
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
uchar value = gray.at<uchar>(y,x);//uchar value = gray.at<uchar>(10,10);
//uchar value = gray.at<uchar>(Point(x, y));
 qDebug()<<value;
 imshow("gray",gray);


2、读取一个RGB图像的像素值
读一个RGB像素点的像素值
Vec3f intensity = img.at<Vec3f>(y, x); 
float blue = intensity.val[0]; 
float green = intensity.val[1]; 
float red = intensity.val[2];

//示例：查看三通道图片 一个像素点的值

Mat src = imread(IMAGE_PATH(68.jpg));
    if(!src.data)
    {
        qDebug()<<"load failed";
        return;
    }
  Vec3b value =  src.at<Vec3b>(10,20);//Vec3b intensity = img.at<Vec3b>(y, x);
  qDebug()<<(int)value[0]<<(int)value[1]<<(int)value[2]<<endl;
  imshow("src",src);

3、修改像素值
1)灰度图
img.at<uchar>(y, x) = 128;

示例：
Mat src = imread(IMAGE_PATH(head1.png));
if(src.empty())
    {
        qDebug()<<"falied";
        return;
    }
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
for(int i = 0;i < 100;i++)
{
    for(int j = 0;j < 100;j++)
    {
        gray.at<uchar>(j,i) = 0;
    }
}
imshow("test", gray);

2)RGB图
img.at<Vec3b>(y,x)[0]=128; // blue
img.at<Vec3b>(y,x)[1]=128; // green
img.at<Vec3b>(y,x)[2]=128; // red

示例：
Mat src = imread(IMAGE_PATH(head1.png));
for(int i = 0;i < 100;i++)
{
    for(int j = 0;j < 100;j++)
    {
        src.at<Vec3b>(j,i)[0] = 255;
        src.at<Vec3b>(j,i)[1] = 255;
        src.at<Vec3b>(j,i)[2] = 255;
    }
}
imshow("test", src);

//练习：显示灰度图和RGB图片的反差图片  255-value



3)空白图像赋值img = Scalar(0);
img = Scalar(0, 0, 255);

示例：
Mat src;
src.create(300, 400, CV_8UC3);
src = Scalar(0, 0, 255);
imshow("test", src);

4)ROI(感兴趣区域)选择
Rect r(10, 10, 100, 100); 
Mat smallImg = img(r);

示例：
 Mat src = imread(IMAGE_PATH(68.jpg));
    Rect rect(10,10,100,150);
    Mat dst = src(rect);
    imshow("dst",dst);
    imshow("src",src);

4、Vec3b与Vec3f
1)Vec3b对应三通道的顺序是blue、green、red的uchar类型数据。
	Vec3f对应三通道的float类型数据

Vec3f value = img.at<Vec3f>(y, x); 
float blue = value.val[0]; //value[0]
float green = value.val[1]; 
float red = value.val[2];


2)把CV_8UC1转换到CV32F1实现如下：
src.convertTo(dst, CV_32F);

读一个GRAY像素点的像素值（CV_8UC1）
Scalar value = img.at<uchar>(y, x); 
或者 Scalar value = img.at<uchar>(Point(x, y));

示例：
 Mat src = imread(IMAGE_PATH(68.jpg));
     Mat gray;
     cvtColor(src,gray,CV_BGR2GRAY);
     Mat dst;
     dst.create(src.size(),src.type());
     gray.convertTo(dst,CV_32F);
     imshow("src",src);
     imshow("gray",gray);
     imshow("dst",dst);
	 
	 
/********************************
 Mat src = imread(IMAGE_PATH(lovely.jpg));
    Mat dst = Mat::zeros(src.size(),src.type());
    int rows = src.rows;
    int cols = src.cols;

    float a = 2.0f;
    float b = 20.f;
    for(int i = 0 ; i <rows; i++)
    {
        for(int j = 0 ; j <cols;j++)
        {
            Vec3b point = src.at<Vec3b>(i,j);
            dst.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(point[0]*a+b);
             dst.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(point[0]*a+b);
             dst.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(point[0]*a+b);
        }
    }
    imshow("src",src);
    imshow("dst",dst);
**********************************/


二、图像混合
1、线性混合操作
g(x) = (1-a)*f0(x) + a*f1(x)
a的取值在0~1之间

2、相关API

void addWeighted(	InputArray src1,    //输入图像1
									double alpha, 			//图像1的alpha值（透明度）
									InputArray src2,		//输入图像2
									double beta, 				//图像2的alpha值
									double gamma, 			//加在每个和上的标量
									OutputArray dst, 		//输出的混合图像
									int dtype = -1);

示例：合成的两个图片需要一样大
Mat src1 = imread("d:/farsight/opencv/testres/bg1.jpg");
Mat src2 = imread("d:/farsight/opencv/testres/bg2.jpg");
Mat dst;
if(src1.rows==src2.rows && src1.cols==src2.cols && src1.type()==src2.type())
{
    float a = 0.7;
    //addWeighted(src1, a, src2, 1.0-a, 0, dst);
    add(src1, src2, dst);
    namedWindow("test", CV_WINDOW_AUTOSIZE);
    imshow("test", dst);
}
练习：自定义图像合成函数
void myAddWeight(Mat src1, float a1, Mat src2, float a2, Mat& output)
{
    int width = src1.cols*src1.channels();
    int height = src1.rows;
    output.create(src1.size(), src1.type());
    for(int y = 0;y < height;y++)
    {
        uchar* line1 = src1.ptr(y);
        uchar* line2 = src2.ptr(y);
        uchar* oline = output.ptr(y);
        for(int x = 0;x < width;x++)
        {
            oline[x] = saturate_cast<uchar>(line1[x]*a1+line2[x]*a2);
        }
    }
}

三、调整图像亮度和对比度
1、理论
g(i, j) = a*f(i, j) + b
a>0对比度，当a大于1时对比度更强
b亮度，像素值越大越接近白色

2、重要的API
Mat new_image = Mat::zeros( image.size(), image.type() );  
创建一张跟原图像大小和类型一致的空白图像、像素值初始化为0
saturate_cast<uchar>(value)确保值大小范围为0~255之间
Mat.at<Vec3b>(y,x)[index]=value 给每个像素点每个通道赋值

示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst = Mat::zeros(src.size(), src.type());
int rows = src.rows;
int cols = src.cols;

float a = 2.0f;
float b = 20.f;    

for(int i = 0;i < rows;i++)
{
    for(int j = 0;j < cols;j++)
    {
        Vec3b point = src.at<Vec3b>(i, j);
        dst.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(point[0]*a+b);
        dst.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(point[1]*a+b);
        dst.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(point[2]*a+b);
    }
}

imshow("test1", src);
imshow("test2", dst);


四、opencv（BGR）图片转换成qt图片（RGB）

示例：（png格式图片会出现问题）
Mat src = imread(IMAGE_PATH(head1.png));
Mat rgb;
cvtColor(src, rgb, CV_BGR2RGB);
QImage img(rgb.data, rgb.cols, rgb.rows, rgb.cols*rgb.channels(), QImage::Format_RGB888);

显示图片：
1.绘制
QPainter painter(this);
painter.drawImage(0, 0, qtImag);

2.QLabel显示
ui->label->setPixmap(QPixmap::fromImage(img));
	
练习：在qt上实现一个图片查看器，输入一个路径