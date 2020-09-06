#include <math.h>

int ColorScaleBCGYR(double in_value)
{
	// 0.0�`1.0 �͈̔͂̒l���T�[���O���t�B�݂����ȐF�ɂ���
	// 0.0                    1.0
	// ��    ��    ��    ��    ��
	// �ŏ��l�ȉ� = ��
	// �ő�l�ȏ� = ��
	int ret;
	int a = 255;    // alpha�l
	int r, g, b;    // RGB�l
	double  value = in_value;
	double  tmp_val = cos(4 * 3.1415 * value);
	int     col_val = (int)((-tmp_val / 2 + 0.5) * 255);
	if (value >= (4.0 / 4.0)) { r = 255;     g = 0;       b = 0; }   // ��
	else if (value >= (3.0 / 4.0)) { r = 255;     g = col_val; b = 0; }   // ���`��
	else if (value >= (2.0 / 4.0)) { r = col_val; g = 255;     b = 0; }   // �΁`��
	else if (value >= (1.0 / 4.0)) { r = 0;       g = 255;     b = col_val; }   // ���`��
	else if (value >= (0.0 / 4.0)) { r = 0;       g = col_val; b = 255; }   // �`��
	else { r = 0;       g = 0;       b = 255; }   // ��
	ret = (a & 0x000000FF) << 24
		| (r & 0x000000FF) << 16
		| (g & 0x000000FF) << 8
		| (b & 0x000000FF);
	return ret;
}


void ColorScaleBCGYR(int& r, int& g, int& b, int z)
{
	// 0.0�`1.0(255) �͈̔͂̒l���T�[���O���t�B�݂����ȐF�ɂ��� 
	// 0.0                    1.0(255)
	// ��    ��    ��    ��    ��
	// �ŏ��l�ȉ� = ��
	// �ő�l�ȏ� = ��
	//int ret;
	int a = 255;    // alpha�l
	//int r, g, b;    // RGB�l
	double  value = z / 255.; // 255�Ŋ����Ă�B
	double  tmp_val = cos(4 * 3.1415 * value);
	int     col_val = (int)((-tmp_val / 2 + 0.5) * 255);
	if (value >= (4.0 / 4.0)) { r = 255;     g = 0;       b = 0; }   // ��
	else if (value >= (3.0 / 4.0)) { r = 255;     g = col_val; b = 0; }   // ���`��
	else if (value >= (2.0 / 4.0)) { r = col_val; g = 255;     b = 0; }   // �΁`��
	else if (value >= (1.0 / 4.0)) { r = 0;       g = 255;     b = col_val; }   // ���`��
	else if (value >= (0.0 / 4.0)) { r = 0;       g = col_val; b = 255; }   // �`��
	else { r = 0;       g = 0;       b = 255; }   // ��
	//ret = (a & 0x000000FF) << 24
	//	| (r & 0x000000FF) << 16
	//	| (g & 0x000000FF) << 8
	//	| (b & 0x000000FF);
	//return ret;
}