
ʾ����Ŀ��TestMatDay3
һ��ͼ�����
1����ȡһ���Ҷ�ͼ������ֵ
��һ��GRAY���ص������ֵ��CV_8UC1��
Scalar intensity = img.at<uchar>(y, x); 
���� Scalar intensity = img.at<uchar>(Point(x, y));

//ʾ�����鿴��ͨ��ͼƬ һ�����ص��ֵ
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


2����ȡһ��RGBͼ�������ֵ
��һ��RGB���ص������ֵ
Vec3f intensity = img.at<Vec3f>(y, x); 
float blue = intensity.val[0]; 
float green = intensity.val[1]; 
float red = intensity.val[2];

//ʾ�����鿴��ͨ��ͼƬ һ�����ص��ֵ

Mat src = imread(IMAGE_PATH(68.jpg));
    if(!src.data)
    {
        qDebug()<<"load failed";
        return;
    }
  Vec3b value =  src.at<Vec3b>(10,20);//Vec3b intensity = img.at<Vec3b>(y, x);
  qDebug()<<(int)value[0]<<(int)value[1]<<(int)value[2]<<endl;
  imshow("src",src);

3���޸�����ֵ
1)�Ҷ�ͼ
img.at<uchar>(y, x) = 128;

ʾ����
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

2)RGBͼ
img.at<Vec3b>(y,x)[0]=128; // blue
img.at<Vec3b>(y,x)[1]=128; // green
img.at<Vec3b>(y,x)[2]=128; // red

ʾ����
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

//��ϰ����ʾ�Ҷ�ͼ��RGBͼƬ�ķ���ͼƬ  255-value



3)�հ�ͼ��ֵimg = Scalar(0);
img = Scalar(0, 0, 255);

ʾ����
Mat src;
src.create(300, 400, CV_8UC3);
src = Scalar(0, 0, 255);
imshow("test", src);

4)ROI(����Ȥ����)ѡ��
Rect r(10, 10, 100, 100); 
Mat smallImg = img(r);

ʾ����
 Mat src = imread(IMAGE_PATH(68.jpg));
    Rect rect(10,10,100,150);
    Mat dst = src(rect);
    imshow("dst",dst);
    imshow("src",src);

4��Vec3b��Vec3f
1)Vec3b��Ӧ��ͨ����˳����blue��green��red��uchar�������ݡ�
	Vec3f��Ӧ��ͨ����float��������

Vec3f value = img.at<Vec3f>(y, x); 
float blue = value.val[0]; //value[0]
float green = value.val[1]; 
float red = value.val[2];


2)��CV_8UC1ת����CV32F1ʵ�����£�
src.convertTo(dst, CV_32F);

��һ��GRAY���ص������ֵ��CV_8UC1��
Scalar value = img.at<uchar>(y, x); 
���� Scalar value = img.at<uchar>(Point(x, y));

ʾ����
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


����ͼ����
1�����Ի�ϲ���
g(x) = (1-a)*f0(x) + a*f1(x)
a��ȡֵ��0~1֮��

2�����API

void addWeighted(	InputArray src1,    //����ͼ��1
									double alpha, 			//ͼ��1��alphaֵ��͸���ȣ�
									InputArray src2,		//����ͼ��2
									double beta, 				//ͼ��2��alphaֵ
									double gamma, 			//����ÿ�����ϵı���
									OutputArray dst, 		//����Ļ��ͼ��
									int dtype = -1);

ʾ�����ϳɵ�����ͼƬ��Ҫһ����
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
��ϰ���Զ���ͼ��ϳɺ���
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

��������ͼ�����ȺͶԱȶ�
1������
g(i, j) = a*f(i, j) + b
a>0�Աȶȣ���a����1ʱ�Աȶȸ�ǿ
b���ȣ�����ֵԽ��Խ�ӽ���ɫ

2����Ҫ��API
Mat new_image = Mat::zeros( image.size(), image.type() );  
����һ�Ÿ�ԭͼ���С������һ�µĿհ�ͼ������ֵ��ʼ��Ϊ0
saturate_cast<uchar>(value)ȷ��ֵ��С��ΧΪ0~255֮��
Mat.at<Vec3b>(y,x)[index]=value ��ÿ�����ص�ÿ��ͨ����ֵ

ʾ����
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


�ġ�opencv��BGR��ͼƬת����qtͼƬ��RGB��

ʾ������png��ʽͼƬ��������⣩
Mat src = imread(IMAGE_PATH(head1.png));
Mat rgb;
cvtColor(src, rgb, CV_BGR2RGB);
QImage img(rgb.data, rgb.cols, rgb.rows, rgb.cols*rgb.channels(), QImage::Format_RGB888);

��ʾͼƬ��
1.����
QPainter painter(this);
painter.drawImage(0, 0, qtImag);

2.QLabel��ʾ
ui->label->setPixmap(QPixmap::fromImage(img));
	
��ϰ����qt��ʵ��һ��ͼƬ�鿴��������һ��·��