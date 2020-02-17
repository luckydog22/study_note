һ��������Ĥ

1����Ҫ����
1.��ȡͼ������ָ��
Mat src;
src.ptr<uchar>(i) ��ȡͼ�����ص�ָ�룬i��ʾ��i��

2.ͨ����
src.channels()

3.λͼ���
src.depth()��������ֵ
CV_8U - 8-bit unsigned integers ( 0..255 )
CV_8S - 8-bit signed integers ( -128..127 )
CV_16U - 16-bit unsigned integers ( 0..65535 )
CV_16S - 16-bit signed integers ( -32768..32767 )
CV_32S - 32-bit signed integers ( -2147483648..2147483647 )
CV_32F - 32-bit floating-point numbers ( -FLT_MAX..FLT_MAX, INF, NAN ) 
CV_64F - 64-bit floating-point numbers ( -DBL_MAX..DBL_MAX, INF, NAN )


2�����ط�Χ����
saturate_cast<uchar>(-100) ����0 
saturate_cast<uchar>(100)	 ����100
saturate_cast<uchar>(288)  ����255

3����ʽ
�������Ĥ����ʮ�ּ򵥣�������Ĥ������ÿ�����ص�����ֵ���Ӷ������Աȶȣ���Ĥ��maskҲ������kernel��
I(i,j) = 5*I(i,j)-[I(i+1,j)+I(i-1,j)+I(i,j+1)+I(i,j-1)]

-          -
| 0  -1  0 |
| -1  5  -1|
| 0  -1  0 |
-					 -
��ɫ���������أ����ϵ��£������ң���ÿ��������ͬ���Ĵ���������õ����ս�����ǶԱȶ����֮������ͼ���mat����

ʾ����TestKernel
ʾ��1��
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = Mat(src.size(), src.type());//type������ȣ�depth����ͨ������channel��
imshow("test1",src);
int rows = src.rows;
int cols = src.cols*src.channels();
int xoffset = src.channels();

for(int i = 1;i < rows-1;i++)//�������в�����
{
    uchar* current = src.ptr<uchar>(i);
    uchar* pre = src.ptr<uchar>(i-1);
    uchar* next = src.ptr<uchar>(i+1);
    uchar* dstptr = dst.ptr<uchar>(i);
	
    for(int j = xoffset;j < cols-xoffset;j++)//�������в�����
    {
        dstptr[j] = saturate_cast<uchar>(5*current[j] - (pre[j]+next[j]+current[j+xoffset]+current[j-xoffset]));
	
   }
}  
imshow("test2",dst);

saturate_cast<uchar> ��������㣬�������Ʒ�Χ��0-255֮��
�Աȶ���� �йٸ�ǿ��


ʾ��2��
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
            Mat dst = Mat(src.size(),src.type());//������Ⱥ�ͨ����
            int width= src.size().width*src.channels();//src.cols
            int height = src.size().height;//src.rows
            int offset = src.channels();
            for(int y = 1; y <height-1; y++)//���������� �������в�����
            {
                uchar* current = src.ptr<uchar>(y);//��ǰ��
                uchar* per = src.ptr<uchar>(y-1);//��һ��
                uchar* next = src.ptr<uchar>(y+1);//��ǰ��
                uchar* dstLine = dst.ptr<uchar>(y);//��ǰ��
                for(int x = offset; x<width-offset; x++)//���������  �������в�����
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

4������filter2D����
������Ĥ������¡��
Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
0 -1 0
-1 5 -1
0 -1 0
filter2D(src, dst, src.depth(), kernel);����src��dst��Mat���ͱ���

//filter2D(src, dst, -1, kernel);
ʾ����
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = Mat(src.size(), src.type());//������Ⱥ�ͨ����
imshow("test1",src);
Mat kernel = (Mat_<char>(3,3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
filter2D(src, dst, src.depth(), kernel);
imshow("test2",dst);


��ϰ��������Ƶ����ÿһ֡ͼ�������Ĥ����
VideoCapture vc;
if(!vc.open(0))//��������ͷ
{
    qDebug()<<"����ͷ��ʧ��";
}
//namedWindow("��Ĥǰ");
//namedWindow("��Ĥ��");
while(true)
{
    Mat frame;
    vc>>frame;//��ȡһ֡����
	 if(!frame.data)
        {
            break;
        }
    Mat dst = Mat(frame.size(), frame.type());
    Mat kernel = (Mat_<char>(3, 3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(frame, dst, frame.depth(), kernel);
    imshow("��Ĥǰ", frame);
    imshow("��Ĥ��", dst);
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

 

����Mat����
1������������С���ͼƬ����ά���飩

2��Mat���ò���
1.void copyTo(Mat mat) ����ͼ�����
ʾ����
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst;
src.copyTo(dst);
imshow("test",dst);

    
2.Mat clone()		����ͼ�����
ʾ����
Mat src = imread(IMAGE_PATH(head3.jpg));
Mat dst = src.clone();
imshow("test",dst);

3.void convertTo(Mat dst, int type) ����ת����KNN�㷨���õ���
4.int channels()  ͨ����
5.int type()	����Ԫ�����ͣ���CV_32FC3
6.int depth()  ������ȣ�ͨ���е�Ԫ�����ͣ���CV_32F�� 
7.bool empty() �ж�����Ϊ�� data 
8.uchar* ptr(i=0) ���i�е�ָ��

3�����ָ��ƺ���ȫ����(�����ǳ����)
Mat A = imread(filepath);
Mat B(A);//���ָ���  ֻ����A������ͷ��ָ�벿�֣����������ݲ���

//��ȫ����(���)
clone()��copyTo()


************************************************
��һ�����ߣ�ǳ����һ��仯������ɵ����ı�
************************************************
ʾ����
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


4��Mat����
1)���캯��
Mat m(2, 3, CV_8UC3, Scalar(0, 0, 255));
����1�Ͳ���2�ֱ��ʾMat�ĸ߶ȣ�raw���Ϳ�ȣ�column��
����3��ʾ��������ͣ�CV_{8U,16S,16U,32S,32F,64F}C{1,2,3}
����4������ʾ��ÿ��Ԫ�صĳ�ʼ��ֵ�������ĳ��Ⱥ�ͨ����һ��

ʾ����
	Mat src = Mat(400/*�߶�*/, 500/*���*/, CV_8UC3, Scalar(0, 0, 255));
	imshow("test", src);

2)create����
	Mat m;
    m.create(400/*�߶�*/,200/*���*/,CV_8UC3);
    m = Scalar(127,0,255);
    imshow("src",m);
	cout<<m<<endl;
    //����
    Mat src= Mat(400,500,CV_8UC3,Scalar(0,0,255));
    imshow("test",src);
m��cout<<m<<endl;
��ȡ����
[127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,  
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,  
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   
 0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255, 127,   0, 255,

5������С����
Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);     
cout << "C = " << endl << " " << C << endl;
/*
Mat C = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl;*/

��������
C = 
 [  0,  -1,   0;
  -1,   5,  -1;
   0,  -1,   0]

��ϰ������7��100x100��ͼ����ʾ����ɫ�ֱ��Ǻ�Ȼ���������

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