
һ�������븯ʴ
1��ͼ����̬ѧ������
	1.������״��һϵ��ͼ����ļ��ϣ���Ҫ�ǻ��ڼ����ۻ����ϵ���̬ѧ��ѧ
	2.��̬ѧ���ĸ��������������͡���ʴ��������
	3.�����븯ʴ��ͼ��������õ���̬ѧ�����ֶ�
2�����ͣ�������������ƣ�������ͼ��A�ͽṹԪ��B���ṹԪ��B��A�����ƶ�������B����������Ϊê�㣬
		����B������A���������ֵ�����滻ê������أ�����B��Ϊ�ṹ�������������״
		
3����ʴ����ʴ�����Ͳ����Ĺ������ƣ�Ψһ��ͬ��������Сֵ�滻ê���ص���ͼ�������ֵ

4����ýṹ
Mat getStructuringElement(int shape, 				//�ṹ��״MorphShapes
												  Size ksize, 			//�ṹ�ߴ�  ����
												  Point anchor = Point(-1,-1));//�ṹê��
												  
5������
void dilate( InputArray src, 
						 OutputArray dst, 
						 InputArray kernel,
             Point anchor = Point(-1,-1), 
             int iterations = 1,				//���ʹ���
             int borderType = BORDER_CONSTANT,
             const Scalar& borderValue = morphologyDefaultBorderValue() );
             
ʾ����
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 20));
dilate(src, dst, kernel);
imshow("src", src);
imshow("dst", dst);


6����ʴ
void erode( InputArray src, 
						OutputArray dst, 
						InputArray kernel,
            Point anchor = Point(-1,-1), 
            int iterations = 1,
            int borderType = BORDER_CONSTANT,
            const Scalar& borderValue = morphologyDefaultBorderValue() );
            
ʾ����
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 20));
erode(src, dst, kernel);
imshow("src", src);
imshow("dst", dst);

           
                   
8���ܽᣬ���Ϳ����������򣻸�ʴ������������

��ϰ����qt�����зֱ�ͨ���������������������ͺ͸�ʴ��Ч�����ı�StructuringElement��size��ֵ��

������̬ѧ����
1����̬ѧ�������������͡���ʴ�������ա���̬ѧ�ݶȡ���ñ����ñ

2��
void morphologyEx( InputArray src, 
									 OutputArray dst,
                   int op, 									//��̬ѧ���� MorphTypes
                   InputArray kernel,
                   Point anchor = Point(-1,-1), 
                   int iterations = 1,
                   int borderType = BORDER_CONSTANT,
                   const Scalar& borderValue = morphologyDefaultBorderValue() );
                   
3�������ȸ�ʴ������    ����ϸ΢����������

ʾ����
Mat src = imread(IMAGE_PATH(dilateanderode2.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(31, 31));
morphologyEx(src, dst, MORPH_OPEN, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

4���գ������ͺ�ʴ		 ����ϸ΢�ĺڰ�����

ʾ����
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(37, 37));
morphologyEx(src, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

5����̬ѧ�ݶȣ����ͼ���ʴ       ��ȡ����

ʾ����
Mat src = imread(IMAGE_PATH(dilateanderode1.jpg));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_GRADIENT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

6����ñ��ԭͼ���������   �õ���ԭͼ������Ļ��Ʋ���

ʾ����
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_TOPHAT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

7����ñ���ղ�����ԭͼ��   �õ���ԭͼ������Ļ��Ʋ���

ʾ����
Mat src = imread(IMAGE_PATH(head1.png));
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 21));
morphologyEx(src, dst, MORPH_BLACKHAT, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

������̬ѧӦ��

1��������ֱ��ֱ��
Mat src = imread(IMAGE_PATH(lines.jpg));
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(21, 1));
morphologyEx(gray, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

2������ˮƽ��ֱ��
Mat src = imread(IMAGE_PATH(lines.jpg));
Mat gray;
cvtColor(src, gray, CV_BGR2GRAY);
Mat dst;
Mat kernel = getStructuringElement(MORPH_RECT, Size(1, 21));
morphologyEx(gray, dst, MORPH_CLOSE, kernel);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

3������С��Χ����
Mat src = imread(IMAGE_PATH(text.jpg));
Mat grayImg;
cvtColor(src, grayImg, CV_BGR2GRAY);
Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
Mat dst;
morphologyEx(grayImg, dst, MORPH_CLOSE, kernel);
medianBlur(dst, dst, 7);
imshow("src", src);
imshow("dst", dst);
waitKey(0);

�ġ�������ֵ����

1��ʲô����ֵ��
�����ȥ���г���ƻ����������ʲô��ѡ��

2����ֵ����
1.��ֵ��ֵ�� THRESH_BINARY��С����ֵ��ֵ���㣬������ֵ��ֵ�����ֵ
2.��ֵ����ֵ�� THRESH_BINARY_INV��С����ֵ��ֵ�����ֵ��������ֵ��ֵ����
3.�ض� THRESH_TRUNC��С����ֵ��ֵ���䣬������ֵ��ֵ����ֵ
4.��ֵȡ�� THRESH_TOZERO��С����ֵ��ֵ���㣬������ֵ��ֵ����
5.��ֵ��ȡ�� THRESH_TOZERO_INV��С����ֵ��ֵ���䣬������ֵ��ֵ����

3���Զ�������ֵ�������㷨��ֻ�����ڵ�ͨ��ͼ��ʹ���㷨ʱ���Զ�������ֵ������thresh��ʧЧ
THRESH_OTSU
THRESH_TRIANGLE

4��double threshold( InputArray src, 
										 OutputArray dst,
                     double thresh, 		//�Զ�����ֵ
                     double maxval, 		//���ֵ
                     int type );				//��ֵ�����Լ��Զ�������ֵ����
                     //����ֵ���Զ������������ֵ
                     
ʾ��������ֵ��ֵ��

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 127, 255, THRESH_BINARY);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

ʾ��������ֵ����ֵ��

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 127, 255, THRESH_BINARY_INV);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

ʾ�������ض�

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TRUNC);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

ʾ��������ֵȡ��

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

ʾ��������ֵ��ȡ��

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO_INV);
imshow("img", img);
imshow("dst", dstImg);
waitKey(0);

ʾ������ʹ���㷨�Զ�������ֵ

Mat img = imread(IMAGE_PATH(head1.png));
Mat grayImg, dstImg;
cvtColor(img, grayImg, CV_BGR2GRAY);
double t = threshold(grayImg, dstImg, 70, 255, THRESH_TOZERO_INV|THRESH_OTSU);
imshow("img", img);
imshow("dst", dstImg);
cout<<t<<endl;
waitKey(0);

��ϰ����ֵ��ֵ����ʹ��Trackbar��̬������ֵ����ʾЧ��