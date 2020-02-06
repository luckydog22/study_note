
一、绘制形状和文字
1、直线
void line(InputOutputArray img, //背景图片
					Point pt1, 						//端点1
					Point pt2, 						//端点2
					const Scalar& color,	//颜色
          int thickness = 1, 		//直线宽度
          int lineType = LINE_8, //直线类型LINE_4  LINE_8  LINE_AA(反锯齿)
          int shift = 0);				//点坐标中小数位数

示例：
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
line(bg, Point(0, 0), Point(250, 250), Scalar(0, 0, 255));
imshow("test", bg);
          
2、矩形
void rectangle(Mat& img, 							//背景图片
							 Rect rec,							//矩形的范围
               const Scalar& color, 	//颜色
               int thickness = 1,			//线条宽度
               int lineType = LINE_8, //线条类型LINE_4  LINE_8  LINE_AA(反锯齿)
               int shift = 0);				//点坐标中小数位数
  
示例：            
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
rectangle(bg, Rect(0, 0, 100, 200), Scalar(0, 0, 255));
imshow("test", bg);
               
3、椭圆
void ellipse(InputOutputArray img, 			//背景图片
						 const RotatedRect& box, 		//椭圆的范围
						 const Scalar& color,
             int thickness = 1, 
             int lineType = LINE_8);
             
RotatedRect构造函数      
RotatedRect(const Point2f& center, //中心点
					  const Size2f& size, 	 //尺寸
					  float angle);					 //角度  顺时针
					  
示例：
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
ellipse(bg, RotatedRect(Point(100, 100), Size(100, 50), 30), Scalar(0, 0, 255));
imshow("test", bg);
					  
4、圆
void circle(InputOutputArray img, 		//背景图片
					  Point center, 						//中心点
					  int radius,								//半径
            const Scalar& color, 
            int thickness = 1,
            int lineType = LINE_8, 
            int shift = 0);
            
示例：
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
circle(bg, Point(100, 100), 50, Scalar(0, 0, 255));
imshow("test", bg);

5、多边形
void polylines(InputOutputArray img, 
							 InputArrayOfArrays pts,		//点数组
               bool isClosed, 						//是否闭合  将最后一个点和第一个点连接在一起
               const Scalar& color,
               int thickness = 1, 
               int lineType = LINE_8, 
               int shift = 0 );
               
示例：
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
vector<Point> points;
points.push_back(Point(0, 0));
points.push_back(Point(10, 10));
points.push_back(Point(0, 20));
points.push_back(Point(20, 0));
points.push_back(Point(30, 30));

polylines(bg, points, true, Scalar(255, 0, 0), 2);

imshow("test", bg);

               
6、字体
void putText( InputOutputArray img, 
							const String& text, 
							Point org,									//文本左下角位置
              int fontFace, 							//字体  参考HersheyFonts
              double fontScale, 					//缩放
              Scalar color,
              int thickness = 1, int lineType = LINE_8,
              bool bottomLeftOrigin = false );//是否翻转
              
示例：
Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
putText(bg, "hello world", Point(0, 500), FONT_ITALIC, 1, Scalar(0, 0, 255));
imshow("test", bg);

7、随机
RNG随机类
int uniform(int a, int b);//[a, b)区间
float uniform(float a, float b);
double uniform(double a, double b);

示例：
RNG rng;
for(int i = 0;i < 10;i++)
{
    cout<<rng.uniform(0, 100)<<endl;
}

练习：随机绘制10条直线，颜色、宽度、位置都随机

Mat bg(500, 500, CV_8UC3, Scalar(255, 255, 255));
RNG rng(time(0));

for(int i = 0;i < 10;i++)
{
    Point p1(rng.uniform(0, 500), rng.uniform(0, 500));
    Point p2(rng.uniform(0, 500), rng.uniform(0, 500));
    Scalar color(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    int width = rng.uniform(1, 5);
    line(bg, p1, p2, color, width, LINE_AA);
}

imshow("test", bg);

二、模糊图像
1、均值滤波器  核中所有点的平均值

void blur( InputArray src, 
					 OutputArray dst,
           Size ksize, 		//核（窗口）尺寸   尺寸为奇数
           Point anchor = Point(-1,-1), //锚点，默认为中点
           int borderType = BORDER_DEFAULT );//边框外推方式BorderTypes

1	1	1	1	1
1	1	1	1	1
1	1	1	1	1
1	1	1	1	1
1	1	1	1	1

示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
blur(src, dst, Size(7, 7));
imshow("src", src);
imshow("dst", dst);


2、高斯滤波器  
高斯平滑：将窗口内的像素点调整为高斯分布

void GaussianBlur( InputArray src, 
									 OutputArray dst, 
									 Size ksize,			//核（窗口）尺寸  尺寸为奇数
                   double sigmaX, 	//x方向系数  如果为0则根据公式自动生成系数
                   double sigmaY = 0,//y方向系数  如果为0则根据公式自动生成系数
                   int borderType = BORDER_DEFAULT );
                   
1		4		7		4		1
7		26	41	26	7	
1		4		7		4		1

示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
GaussianBlur(src, dst, Size(7, 7), 0, 0);
imshow("src", src);
imshow("dst", dst);

                   
3、中值滤波器	将窗口内的像素点排序，将排序后正中间的值替换窗口中间的像素点（对椒盐噪声效果较好）

void medianBlur( InputArray src, 
								 OutputArray dst, 
								 int ksize );
								 
示例：
Mat src = imread(IMAGE_PATH(head4.jpg));
Mat dst;
medianBlur(src, dst, 7);
imshow("src", src);
imshow("dst", dst);

4、双边滤波器 
双边平滑：对窗口内个像素点进行加权平均。权重有两部分组成：1.同高斯平滑 2.高斯权重。
可以将双边平滑当做是高斯平滑，只是相似程度更高的像素权值更高，边缘更加清晰对比度更高。

加权平均：加权平均值即将各数值乘以相应的权数，然后加总求和得到总体值，再除以总的单位数。

void bilateralFilter( InputArray src, 
										  OutputArray dst, 
										  int d,							//窗口大小  如果d值小于0，会根据sigmaSpace自动计算
                      double sigmaColor, 	//颜色空间滤波系数  值越大越容易和周围像素混合（对比度越低）
                      double sigmaSpace,	//坐标空间滤波系数  邻域的大小，d大于零时应该和d保持正比
                      int borderType = BORDER_DEFAULT );
                      
示例：
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
bilateralFilter(src, dst, 15, 100, 15);
imshow("src", src);
imshow("dst", dst);

练习1：对图片进行双边滤波，然后使用filter2D增强图片对比度

练习2：打开摄像头，对摄像头中的自己进行“美颜”


三、直方图（Histogram）
1、图像直方图：是指对整个图像在灰度范围内的像素值(0~255)统计出现频率次数，据此生成的直方图，
		称为图像直方图-直方图。直方图反映了图像灰度的分布情况。是图像的“统计学”特征。
		
2、直方图均值化：是一种提高图像对比度的方法，拉伸图像灰度值范围。
1.如何实现，通过上通过像素映射remap我们知道可以将图像灰度分布从一个分布映射到另外一个分布，
		然后在得到映射后的像素值即可。
2.
void equalizeHist( InputArray src, 
									 OutputArray dst );	

示例：
Mat src = imread("d:/farsight/opencv/testres/head1.png");
Mat gray, dst;
cvtColor(src, gray, CV_BGR2GRAY);
imshow("gray", gray);
equalizeHist(gray, dst);
imshow("dst", dst);							 
									 						 
3、创建直方图
1.将多通道数组划分为多个单通道数组
void split(const Mat& src, 
				   Mat* mvbegin);
				   
2.创建直方图
void calcHist( const Mat* images,  //要生成直方图的Mat数组，可以对多个图像同时进行分析得到一个直方图
							 int nimages,				 //images数组的元素个数
               const int* channels, //每个图片要计算的通道
               InputArray mask,			//掩膜数组，必须是8-bit数组并且与images中的数组同size，如果不需要掩膜传cv::noArray()
               OutputArray& hist, 	//输出值，是一个一维数组
               int dims,						//直方图的维度，恰好是channels数组的元素个数
               const int* histSize,  //直方图每个维度的区间的个数(输出值hist的数组长度)  int size[n];
               const float** ranges,	//直方图每个维度的需要统计的值的范围，例如｛20，30｝就是把20~30前闭后开区间的值都进行统计，应定义成二维数组，数组长度必须为dims		float range1[] = {0, 1000}; const float* ranges[] = {range1};
               bool uniform = true,  //ranges中的数据的解释方式，一般选true
               bool accumulate = false );//把images转换为直方图之前不要将其中元素删除
               
3.归一化：将数组中的值按照比例缩放
void normalize( InputArray src, 
							  InputOutputArray dst, 
							  double alpha = 1, 			//归一化每个元素的最小值
							  double beta = 0,				//归一化每个元素的最大值
                int norm_type = NORM_L2,//NORM_MINMAX 按照比例缩放方式来进行归一化处理
                int dtype = -1, 				//深度值，-1和原来数组一样
                InputArray mask = noArray());//掩码

示例：
Mat src = imread("d:/farsight/opencv/testres/head1.png");
Mat signal_images[3];
split(src, signal_images);//将各个通道分离，存放到signal_images中
int channel = 0;
Mat dst;
int size = 500;
float range[2] = {0, 256};
const float* ranges[1] = {range};
Scalar colors[3] = {Scalar(255,0,0),Scalar(0,255,0),Scalar(0,0,255)};
char* showTitles[3] = {"showB","showG","showR"};
for(int i = 0;i < 3;i++)
{
    calcHist(&signal_images[i], //只以一个维度来创建直方图
    1, //数组元素个数为1
    &channel,//因为输入Mat只有一个通道，所以只能选择0通道
    noArray(),//不要掩膜操作
    dst,//输出
    1,//因为输入的Mat对象维度是1
    &size,//设立500个区间
    ranges);//统计范围是0~256前闭后开区间
    //归一化
    normalize(dst, dst, 0, 100, NORM_MINMAX);
    int showWidth = dst.size().height;//height是dst的数组长度
    int showHeight = 300;
    Mat showImg(Size(showWidth, showHeight), CV_8UC3);
    for(int j = 0;j < showWidth;j++)
    {
        line(showImg,Point(j, showHeight-dst.at<float>(j)),Point(j, showHeight),colors[i],1,LINE_AA);
    }
    imshow(showTitles[i], showImg);
}