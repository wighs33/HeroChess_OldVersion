#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include "board.h"
#include "Castle.h"
#include "Wizard.h"
#include "Reaper.h"
#include "Ninja.h"
#include "Ghost.h"
#include "Warrior.h"
#include "Defender.h"
#include "Knight.h"
#include "Player.h"

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Hero Chess";

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int winW = 560;
int winH = 780;

void atkCastle(HWND hWnd, Castle& ca,Mal& mal, Board b, Player p1, int itx, int ity)
{
	if (ca.getLife() == 2)
	{
		ca.setLife(1);
		mal.setSelect(0);// ���� ���� ǥ�� off
		mal.setAblTurn(1);
	}
	else if (ca.getLife() == 1)
	{
		if (p1.getTurn() == 1)
			MessageBox(hWnd, _T("player1�� �¸��Ͽ����ϴ�."), _T("WIN"), MB_OK);
		else
			MessageBox(hWnd, _T("player2�� �¸��Ͽ����ϴ�."), _T("WIN"), MB_OK);
		DestroyWindow(hWnd);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, winW, winH, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, mem1dc, mem2dc;
	PAINTSTRUCT ps;
	static HBITMAP hBit, hBitBack, oldBit1, oldBit2;
	static HBITMAP caBit,fiBit, wiBit[16],reBit[5], niBit[12],ghBit[9], waBit[7], deBit[3], knBit[9];
	static HPEN hPen, oldPen;
	static Board b;

	static Castle ca1, ca2;
	static Wizard wi1, wi2;
	static Reaper re1, re2;
	static Ninja ni1, ni2;
	static Ghost gh1, gh2;
	static Warrior wa1,wa2;
	static Defender de1, de2;
	static Knight kn1, kn2;

	static Player p1,p2;

	static int mx, my;
	static int itx, ity;// malPos�ε��� �ӽ������

	static int tmpY;
	static int tmpX;

	switch (uMsg) {
	case WM_CREATE:
		//���� ��ǥ �ʱ�ȭ
		b.getY()[0] = 60;
		b.getX()[0] = 60;
		for (int iy = 1; iy < 10; ++iy)
			b.getY()[iy] = b.getY()[iy - 1] + 60;

		for (int ix = 1; ix < 7; ++ix)
			b.getX()[ix] = b.getX()[ix - 1] + 60;

		//���� ��ġ �ʱ�ȭ
		wi1.setX(b.getX()[0]);				wi1.setY(b.getY()[1]);
		re1.setX(b.getX()[1]);				re1.setY(b.getY()[1]);
		ni1.setX(b.getX()[2]);				ni1.setY(b.getY()[1]);
		gh1.setX(b.getX()[3]);			gh1.setY(b.getY()[1]);
		wa1.setX(b.getX()[4]);			wa1.setY(b.getY()[1]);
		de1.setX(b.getX()[5]);			de1.setY(b.getY()[1]);
		kn1.setX(b.getX()[6]);			kn1.setY(b.getY()[1]);

		wi2.setX(b.getX()[6]);				wi2.setY(b.getY()[8]);
		re2.setX(b.getX()[5]);				re2.setY(b.getY()[8]);
		ni2.setX(b.getX()[4]);				ni2.setY(b.getY()[8]);
		gh2.setX(b.getX()[3]);			gh2.setY(b.getY()[8]);
		wa2.setX(b.getX()[2]);			wa2.setY(b.getY()[8]);
		de2.setX(b.getX()[1]);			de2.setY(b.getY()[8]);
		kn2.setX(b.getX()[0]);			kn2.setY(b.getY()[8]);

		//����ȣ ���� �ʱ�ȭ
		b.malPos[1][0] = 1;
		b.malPos[1][1] = 2;
		b.malPos[1][2] = 3;
		b.malPos[1][3] = 4;
		b.malPos[1][4] = 5;
		b.malPos[1][5] = 6;
		b.malPos[1][6] = 7;
		b.malPos[8][0] = 17;
		b.malPos[8][1] = 16;
		b.malPos[8][2] = 15;
		b.malPos[8][3] = 14;
		b.malPos[8][4] = 13;
		b.malPos[8][5] = 12;
		b.malPos[8][6] = 11;

		//�� �ʱ�ȭ
		p1.setTurn(1);
		p2.setTurn(0);

		hBitBack = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		caBit = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));

		wiBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		wiBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		wiBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		wiBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
		wiBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
		wiBit[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		wiBit[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
		wiBit[7] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
		wiBit[8] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
		wiBit[9] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP12));
		wiBit[10] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		wiBit[11] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP14));
		wiBit[12] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP15));
		wiBit[13] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP16));
		wiBit[14] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		wiBit[15] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP18));

		reBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP19));
		reBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP20));
		reBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP21));
		reBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP22));
		reBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP23));

		niBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP24));
		niBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP25));
		niBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP26));
		niBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP27));
		niBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP28));
		niBit[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP29));
		niBit[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP30));
		niBit[7] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP31));
		niBit[8] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP32));
		niBit[9] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP33));
		niBit[10] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP34));
		niBit[11] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP35));

		ghBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP36));
		ghBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP37));
		ghBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP38));
		ghBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP39));
		ghBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP40));
		ghBit[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP41));
		ghBit[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP42));
		ghBit[7] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP43));
		ghBit[8] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP44));

		waBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP45));
		waBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP46));
		waBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP47));
		waBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP48));
		waBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP49));
		waBit[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP50));
		waBit[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP51));

		deBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP52));
		deBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP53));
		deBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP54));

		knBit[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP55));
		knBit[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP56));
		knBit[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP57));
		knBit[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP58));
		knBit[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP59));
		knBit[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP60));
		knBit[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP61));
		knBit[7] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP62));
		knBit[8] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP63));

		fiBit = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP64));

		SetTimer(hWnd, 1, 70, NULL);
		break;
	case WM_TIMER:
		hdc = GetDC(hWnd);

		if (hBit == NULL)  //--- hBit1�� hdc�� ȣȯ�ǰ� ������ش�: ���⿡ �̹����� ��Ƽ� �����Ϸ��� �� 
			hBit = CreateCompatibleBitmap(hdc, winW, winH);
		mem1dc = CreateCompatibleDC(hdc);
		mem2dc = CreateCompatibleDC(mem1dc);
		oldBit1 = (HBITMAP)SelectObject(mem1dc, hBit);
		oldBit2 = (HBITMAP)SelectObject(mem2dc, hBitBack);
		StretchBlt(mem1dc, 0, 0, winW, winH, mem2dc, 0, 0, 320, 320, SRCCOPY);

		b.draw(mem1dc);	//���ڱ׸���

		//�簢���׸���  ��������
		SetROP2(mem1dc, R2_XORPEN);
		SelectObject(mem1dc, (HBRUSH)GetStockObject(BLACK_BRUSH));



		/*
				//����ȣ Ȯ�ο�
		for(int iy=0;iy<10;++iy)
			for (int ix = 0; ix < 7; ++ix)
			{
				static TCHAR lpOut[100];
				wsprintf(lpOut, _T("%d "), b.malPos[iy][ix]);
				TextOut(mem1dc, b.getX()[ix], b.getY()[iy], lpOut, lstrlen(lpOut));
			}
		*/

		TextOut(mem1dc, b.getX()[3], 20, _T("Player1"), 7);
		TextOut(mem1dc, b.getX()[3], b.getY()[9] + 80, _T("Player2"), 7);


		oldBit2 = (HBITMAP)SelectObject(mem2dc, caBit);
		TransparentBlt(mem1dc, b.getX()[3], b.getY()[0] - 30, 60, 90, mem2dc, 0, 0, 674, 867, RGB(255, 255, 255));		//�� �׸���

		if (ca1.getLife() == 1)
		{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, fiBit);
			TransparentBlt(mem1dc, b.getX()[3], b.getY()[0], 60, 60, mem2dc, 0, 0, 260, 260, RGB(255, 255, 255));		//�� �׸���
		}

		//������
		if (wi1.getX()!=0&& wi1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (wi1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, wi1, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi1.getX(), wi1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
			}
			else if (wi1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi1.cnt]);
				TransparentBlt(mem1dc, wi1.getX(), wi1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				//�̵� ����
				wi1.cnt++;
				if (wi1.cnt == 12)
				{
					//��ġ����
					wi1.setY(wi1.getToY());
					wi1.setX(wi1.getToX());
				}
				if (wi1.cnt == 15)
				{
					wi1.cnt = 0;
					wi1.setMoveAni(0); //�̵� off
					wi1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (wi1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi1.getX(), wi1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, wi1.getX(), wi1.getY(), wi1.getX() + 60, wi1.getY() + 60);
			}
			else if (wi1.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi1.cnt]);
				TransparentBlt(mem1dc, wi1.getX(), wi1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				//�̵� ����
				wi1.cnt++;
				if (wi1.cnt == 12)
				{
					//��ġ����
					wi1.setY(wi1.getToY());
					wi1.setX(wi1.getToX());

					if (wi1.cngMal == 2)
					{
						re1.setY(re1.getToY());
						re1.setX(re1.getToX());
					}
					else if (wi1.cngMal == 3)
					{
						ni1.setY(ni1.getToY());
						ni1.setX(ni1.getToX());
					}
					else if (wi1.cngMal == 4)
					{
						gh1.setY(gh1.getToY());
						gh1.setX(gh1.getToX());
					}
					else if (wi1.cngMal == 5)
					{
						wa1.setY(wa1.getToY());
						wa1.setX(wa1.getToX());
					}
					else if (wi1.cngMal == 6)
					{
						de1.setY(de1.getToY());
						de1.setX(de1.getToX());
					}
					else if (wi1.cngMal == 7)
					{
						kn1.setY(kn1.getToY());
						kn1.setX(kn1.getToX());
					}
				}
				if (wi1.cnt == 15)
				{
					wi1.cnt = 0;
					wi1.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(0);
					p2.setTurn(1);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi1.getX(), wi1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
			}
		}

		//���
		if (re1.getX() != 0 && re1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (re1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, re1, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
				TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
			}
			else if (re1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[4]);
				TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				//�̵� ����
				//��ġ����
				re1.setY(re1.getY()+(re1.getToY() - tmpY) / 10);
				re1.setX(re1.getX() + (re1.getToX() - tmpX) / 10);

				if (re1.getY()== re1.getToY()&& re1.getX() == re1.getToX())
				{
					re1.cnt = 0;
					re1.setMoveAni(0); //�̵� off
					re1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (re1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re1.cnt]);
				TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				re1.cnt++;
				if (re1.cnt == 3)
				{
					re1.cnt = 0;
					re1.setAtkAni(0);//���� off
				}
			}
			else if (re1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
				TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, re1.getX(), re1.getY(), re1.getX() + 60, re1.getY() + 60);
			}
			else if (re1.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re1.cnt]);
				TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				re1.cnt++;
				if (re1.cnt == 3)
				{
					re1.cnt = 0;
					re1.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(0);
					p2.setTurn(1);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
			TransparentBlt(mem1dc, re1.getX(), re1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
			}
		}

		//����
		if (ni1.getX() != 0 && ni1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (ni1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, ni1, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
			}
			else if (ni1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni1.cnt]);
				TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				//�̵� ����
				ni1.cnt++;
				ni1.cnt %= 9;
				//��ġ����
				ni1.setY(ni1.getY() + (ni1.getToY() - tmpY) / 10);
				ni1.setX(ni1.getX() + (ni1.getToX() - tmpX) / 10);

				if (ni1.getY() == ni1.getToY() && ni1.getX() == ni1.getToX())
				{
					ni1.cnt = 0;
					ni1.setMoveAni(0); //�̵� off
					ni1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (ni1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni1.cnt]);
				TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				ni1.cnt++;
				if (ni1.cnt == 3)
				{
					ni1.cnt = 0;
					ni1.setAtkAni(0);//���� off
				}
			}
			else if (ni1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, ni1.getX(), ni1.getY(), ni1.getX() + 60, ni1.getY() + 60);
			}
			else if (ni1.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				ni1.cnt = 0;
				ni1.setAblAni(0);//�ɷ� off
				//������
				p1.setTurn(0);
				p2.setTurn(1);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
			TransparentBlt(mem1dc, ni1.getX(), ni1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
			}
		}

		//��Ʈ
		if (gh1.getX() != 0 && gh1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (gh1.killedBy == 0)
			{
				if (gh1.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
				}
				else if (gh1.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					gh1.cnt++;
					if (gh1.cnt == 5)
						gh1.cnt = 3;
					//��ġ����
					gh1.setY(gh1.getY() + (gh1.getToY() - tmpY) / 10);
					gh1.setX(gh1.getX() + (gh1.getToX() - tmpX) / 10);

					if (gh1.getY() == gh1.getToY() && gh1.getX() == gh1.getToX())
					{
						gh1.cnt = 0;
						gh1.setMoveAni(0); //�̵� off
						if (gh1.getY() == b.getY()[9])	//��Ʈ�� ������� ���� ������ �� �ɷ� �ߵ��Ѵ�.
						{
							gh1.setAblTurn(1);//�ɷ��� on
							gh1.cnt = 6;
						}
						else
						{
							//������
							p1.setTurn(0);
							p2.setTurn(1);
						}
					}
				}
				else if (gh1.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					gh1.cnt++;
					if (gh1.cnt == 3)
					{
						gh1.cnt = 0;
						gh1.setAtkAni(0);//���� off
					}
				}
				else if (gh1.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh1.getX(), gh1.getY(), gh1.getX() + 60, gh1.getY() + 60);
				}
				else if (gh1.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					if (gh1.cnt == 8)
					{
						b.malPos[b.posToIndex(gh1.getY())][b.posToIndex(gh1.getX())] = 0;
						gh1.setY(b.getY()[1]);
						gh1.setX(b.getX()[3]);
						b.malPos[b.posToIndex(gh1.getY())][b.posToIndex(gh1.getX())] = 4;
						gh1.aniTmp = 1;
					}
					if (gh1.aniTmp)
					{
						--gh1.cnt;
						if (gh1.cnt == 5)
						{
							gh1.cnt = 0;
							gh1.aniTmp = 0;
							gh1.setAblAni(0);//�ɷ� off
							//������
							p1.setTurn(0);
							p2.setTurn(1);
						}
					}
					else
						gh1.cnt++;
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
				}
			}
			else if (gh1.killedBy == 11)	//��Ʈ=>������
			{
				if (gh1.getX() != 0 && gh1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
				{
					if (gh1.getSelect() == 1)//����on
					{
						b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
					}
					else if (gh1.getMoveAni() == 1)	//�̵� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi1.cnt]);
						TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						//�̵� ����
						wi1.cnt++;
						if (wi1.cnt == 12)
						{
							//��ġ����
							gh1.setY(gh1.getToY());
							gh1.setX(gh1.getToX());
						}
						if (wi1.cnt == 15)
						{
							wi1.cnt = 0;
							gh1.setMoveAni(0); //�̵� off
							gh1.setAblTurn(1);//�ɷ��� on
						}
					}
					else if (gh1.getAblTurn() == 1)	//�ɷ��� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
						oldPen = (HPEN)SelectObject(mem1dc, hPen);
						Rectangle(mem1dc, gh1.getX(), gh1.getY(), gh1.getX() + 60, gh1.getY() + 60);
					}
					else if (gh1.getAblAni() == 1)	//�ɷ� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi1.cnt]);
						TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						//�̵� ����
						wi1.cnt++;
						if (wi1.cnt == 12)
						{
							//��ġ����
							gh1.setY(gh1.getToY());
							gh1.setX(gh1.getToX());

							if (gh1.cngMal == 2)
							{
								re1.setY(re1.getToY());
								re1.setX(re1.getToX());
							}
							else if (gh1.cngMal == 3)
							{
								ni1.setY(ni1.getToY());
								ni1.setX(ni1.getToX());
							}
							else if (gh1.cngMal == 1)
							{
								wi1.setY(wi1.getToY());
								wi1.setX(wi1.getToX());
							}
							else if (gh1.cngMal == 5)
							{
								wa1.setY(wa1.getToY());
								wa1.setX(wa1.getToX());
							}
							else if (gh1.cngMal == 6)
							{
								de1.setY(de1.getToY());
								de1.setX(de1.getToX());
							}
							else if (gh1.cngMal == 7)
							{
								kn1.setY(kn1.getToY());
								kn1.setX(kn1.getToX());
							}
						}
						if (wi1.cnt == 15)
						{
							wi1.cnt = 0;
							gh1.setAblAni(0);//�ɷ� off
							//������
							p1.setTurn(0);
							p2.setTurn(1);
						}
					}
					else //����x,�̵�x,����x,�ɷ�x
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
					}
				}
			}
			else if (gh1.killedBy == 12)	//��Ʈ-���
			{
				if (gh1.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				}
				else if (gh1.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[4]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					//�̵� ����
					//��ġ����
					gh1.setY(gh1.getY() + (gh1.getToY() - tmpY) / 10);
					gh1.setX(gh1.getX() + (gh1.getToX() - tmpX) / 10);

					if (gh1.getY() == gh1.getToY() && gh1.getX() == gh1.getToX())
					{
						re1.cnt = 0;
						gh1.setMoveAni(0); //�̵� off
						gh1.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh1.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					re1.cnt++;
					if (re1.cnt == 3)
					{
						re1.cnt = 0;
						gh1.setAtkAni(0);//���� off
					}
				}
				else if (gh1.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh1.getX(), gh1.getY(), gh1.getX() + 60, gh1.getY() + 60);
				}
				else if (gh1.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					re1.cnt++;
					if (re1.cnt == 3)
					{
						re1.cnt = 0;
						gh1.setAblAni(0);//�ɷ� off
						//������
						p1.setTurn(0);
						p2.setTurn(1);
					}
				}
			}
			else if (gh1.killedBy == 13)//��Ʈ-����
			{
				if (gh1.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				}
				else if (gh1.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					//�̵� ����
					ni1.cnt++;
					ni1.cnt %= 9;
					//��ġ����
					gh1.setY(gh1.getY() + (gh1.getToY() - tmpY) / 10);
					gh1.setX(gh1.getX() + (gh1.getToX() - tmpX) / 10);

					if (gh1.getY() == gh1.getToY() && gh1.getX() == gh1.getToX())
					{
						ni1.cnt = 0;
						gh1.setMoveAni(0); //�̵� off
						gh1.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh1.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni1.cnt]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					ni1.cnt++;
					if (ni1.cnt == 3)
					{
						ni1.cnt = 0;
						gh1.setAtkAni(0);//���� off
					}
				}
				else if (gh1.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh1.getX(), gh1.getY(), gh1.getX() + 60, gh1.getY() + 60);
				}
				else if (gh1.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					ni1.cnt = 0;
					gh1.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(0);
					p2.setTurn(1);
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				}
			}
			else if (gh1.killedBy == 15)//��Ʈ-����
			{
			if (gh1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
			else if (gh1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa1.cnt]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				//�̵� ����
				if (wa1.cnt < 2)
					wa1.cnt++;
				//��ġ����
				gh1.setY(gh1.getY() + (gh1.getToY() - tmpY) / 10);
				gh1.setX(gh1.getX() + (gh1.getToX() - tmpX) / 10);
				if (gh1.getY() == tmpY + (gh1.getToY() - tmpY) * 8 / 10 && gh1.getX() == tmpX + (gh1.getToX() - tmpX) * 8 / 10)
				{
					wa1.cnt = 4;
				}
				else if (gh1.getY() == gh1.getToY() && gh1.getX() == gh1.getToX())
				{
					wa1.cnt = 0;
					gh1.setMoveAni(0); //�̵� off
					gh1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (gh1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa1.cnt]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				if (wa1.cnt < 3)
				{
					wa1.cnt++;
				}
				else if (wa1.cnt == 3)
				{
					wa1.cnt = 5;
				}
				else if (wa1.cnt == 5)
				{
					wa1.cnt = 6;
				}
				else if (wa1.cnt == 6)
				{
					wa1.cnt = 0;
					gh1.setAtkAni(0);//���� off
				}
			}
			else if (gh1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				gh1.waAbillity(b, p1);
				//������
				gh1.setAblTurn(0);
				p1.setTurn(0);
				p2.setTurn(1);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
			}
			else if (gh1.killedBy == 17)//��Ʈ-���
			{
			if (gh1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, gh1, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
			else if (gh1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn1.cnt]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn1.cnt++;
				kn1.cnt %= 4;
				//��ġ����
				gh1.setY(gh1.getY() + (gh1.getToY() - tmpY) / 10);
				gh1.setX(gh1.getX() + (gh1.getToX() - tmpX) / 10);

				if (gh1.getY() == gh1.getToY() && gh1.getX() == gh1.getToX())
				{
					kn1.cnt = 0;
					gh1.setMoveAni(0); //�̵� off
					gh1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (gh1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn1.cnt]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn1.cnt += 4;
				if (kn1.cnt == 9)
				{
					kn1.cnt = 0;
					gh1.setAtkAni(0);//���� off
				}
				kn1.cnt -= 3;
			}
			else if (gh1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, gh1.getX(), gh1.getY(), gh1.getX() + 60, gh1.getY() + 60);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, gh1.getX(), gh1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
			}
		}

		//����
		if (wa1.getX() != 0 && wa1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (wa1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, wa1, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, wa1.getX(), wa1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
			else if (wa1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa1.cnt]);
				TransparentBlt(mem1dc, wa1.getX(), wa1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				//�̵� ����
				if (wa1.cnt < 2)
					wa1.cnt++;
				//��ġ����
				wa1.setY(wa1.getY() + (wa1.getToY() - tmpY) / 10);
				wa1.setX(wa1.getX() + (wa1.getToX() - tmpX) / 10);
				if (wa1.getY() == tmpY + (wa1.getToY() - tmpY)*8 / 10 && wa1.getX() == tmpX + (wa1.getToX() - tmpX) * 8 / 10)
				{
					wa1.cnt = 4;
				}
				else if (wa1.getY() == wa1.getToY() && wa1.getX() == wa1.getToX())
				{
					wa1.cnt = 0;
					wa1.setMoveAni(0); //�̵� off
					wa1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (wa1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa1.cnt]);
				TransparentBlt(mem1dc, wa1.getX(), wa1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				if (wa1.cnt < 3)
				{
					wa1.cnt ++;
				}
				else if (wa1.cnt == 3)
				{
					wa1.cnt = 5;
				}
				else if (wa1.cnt ==5)
				{
					wa1.cnt = 6;
				}
				else if (wa1.cnt == 6)
				{
					wa1.cnt = 0;
					wa1.setAtkAni(0);//���� off
				}
			}
			else if (wa1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, wa1.getX(), wa1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				wa1.abillity(b, p1);
				//������
				wa1.setAblTurn(0);
				p1.setTurn(0);
				p2.setTurn(1);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
			TransparentBlt(mem1dc, wa1.getX(), wa1.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
		}

		//�����
		if (de1.getX() != 0 && de1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (de1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, de1, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
				TransparentBlt(mem1dc, de1.getX(), de1.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
			}
			else if (de1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[de1.cnt]);
				TransparentBlt(mem1dc, de1.getX(), de1.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				if (de1.cnt < 2)
					de1.cnt++;
				//��ġ����
				de1.setY(de1.getY() + (de1.getToY() - tmpY) / 10);
				de1.setX(de1.getX() + (de1.getToX() - tmpX) / 10);

				if (de1.getY() == de1.getToY() && de1.getX() == de1.getToX())
				{
					de1.cnt = 0;
					de1.setMoveAni(0); //�̵� off
					de1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (de1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
				TransparentBlt(mem1dc, de1.getX(), de1.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, de1.getX(), de1.getY(), de1.getX() + 60, de1.getY() + 60);
			}
			else if (de1.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[de1.cnt]);
				TransparentBlt(mem1dc, de1.getX(), de1.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				if (de1.cnt < 2)
					de1.cnt++;
				//��ġ����
				de1.setY(de1.getY() + (de1.getToY() - tmpY) / 10);
				de1.setX(de1.getX() + (de1.getToX() - tmpX) / 10);

				if (de1.getY() == de1.getToY() && de1.getX() == de1.getToX())
				{
					de1.cnt = 0;
					de1.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(0);
					p2.setTurn(1);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
			TransparentBlt(mem1dc, de1.getX(), de1.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
			}
		}

		//���
		if (kn1.getX() != 0 && kn1.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (kn1.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, kn1, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, kn1.getX(), kn1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
			else if (kn1.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn1.cnt]);
				TransparentBlt(mem1dc, kn1.getX(), kn1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn1.cnt ++;
				kn1.cnt %= 4;
				//��ġ����
				kn1.setY(kn1.getY() + (kn1.getToY() - tmpY) / 10);
				kn1.setX(kn1.getX() + (kn1.getToX() - tmpX) / 10);

				if (kn1.getY() == kn1.getToY() && kn1.getX() == kn1.getToX())
				{
					kn1.cnt = 0;
					kn1.setMoveAni(0); //�̵� off
					kn1.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (kn1.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn1.cnt]);
				TransparentBlt(mem1dc, kn1.getX(), kn1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn1.cnt+=4;
				if (kn1.cnt == 9)
				{
					kn1.cnt = 0;
					kn1.setAtkAni(0);//���� off
				}
				kn1.cnt -= 3;
			}
			else if (kn1.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, kn1.getX(), kn1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, kn1.getX(), kn1.getY(), kn1.getX() + 60, kn1.getY() + 60);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
			TransparentBlt(mem1dc, kn1.getX(), kn1.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
		}

		//p2
		//������
		if (wi2.getX() != 0 && wi2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (wi2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, wi2, b,p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi2.getX(), wi2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
			}
			else if (wi2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi2.cnt]);
				TransparentBlt(mem1dc, wi2.getX(), wi2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				//�̵� ����
				wi2.cnt++;
				if (wi2.cnt == 12)
				{
					//��ġ����
					wi2.setY(wi2.getToY());
					wi2.setX(wi2.getToX());
				}
				if (wi2.cnt == 15)
				{
					wi2.cnt = 0;
					wi2.setMoveAni(0); //�̵� off
					wi2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (wi2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi2.getX(), wi2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, wi2.getX(), wi2.getY(), wi2.getX() + 60, wi2.getY() + 60);
			}
			else if (wi2.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi2.cnt]);
				TransparentBlt(mem1dc, wi2.getX(), wi2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
				//�̵� ����
				wi2.cnt++;
				if (wi2.cnt == 12)
				{
					//��ġ����
					wi2.setY(wi2.getToY());
					wi2.setX(wi2.getToX());

					if (wi2.cngMal == 12)
					{
						re2.setY(re2.getToY());
						re2.setX(re2.getToX());
					}
					else if (wi2.cngMal == 13)
					{
						ni2.setY(ni2.getToY());
						ni2.setX(ni2.getToX());
					}
					else if (wi2.cngMal == 14)
					{
						gh2.setY(gh2.getToY());
						gh2.setX(gh2.getToX());
					}
					else if (wi2.cngMal == 15)
					{
						wa2.setY(wa2.getToY());
						wa2.setX(wa2.getToX());
					}
					else if (wi2.cngMal == 16)
					{
						de2.setY(de2.getToY());
						de2.setX(de2.getToX());
					}
					else if (wi2.cngMal == 17)
					{
						kn2.setY(kn2.getToY());
						kn2.setX(kn2.getToX());
					}
				}
				if (wi2.cnt == 15)
				{
					wi2.cnt = 0;
					wi2.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(1);
					p2.setTurn(0);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
				TransparentBlt(mem1dc, wi2.getX(), wi2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
			}
		}

		//���
		if (re2.getX() != 0 && re2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (re2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, re2, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
			}
			else if (re2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[4]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				//�̵� ����
				//��ġ����
				re2.setY(re2.getY() + (re2.getToY() - tmpY) / 10);
				re2.setX(re2.getX() + (re2.getToX() - tmpX) / 10);

				if (re2.getY() == re2.getToY() && re2.getX() == re2.getToX())
				{
					re2.cnt = 0;
					re2.setMoveAni(0); //�̵� off
					re2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (re2.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re2.cnt]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				re2.cnt++;
				if (re2.cnt == 3)
				{
					re2.cnt = 0;
					re2.setAtkAni(0);//���� off
				}
			}
			else if (re2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, re2.getX(), re2.getY(), re2.getX() + 60, re2.getY() + 60);
			}
			else if (re2.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re2.cnt]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				re2.cnt++;
				if (re2.cnt == 3)
				{
					re2.cnt = 0;
					re2.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(1);
					p2.setTurn(0);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
				TransparentBlt(mem1dc, re2.getX(), re2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
			}
		}

		//����
		if (ni2.getX() != 0 && ni2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (ni2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, ni2, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
			}
			else if (ni2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni2.cnt]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				//�̵� ����
				ni2.cnt++;
				ni2.cnt %= 9;
				//��ġ����
				ni2.setY(ni2.getY() + (ni2.getToY() - tmpY) / 10);
				ni2.setX(ni2.getX() + (ni2.getToX() - tmpX) / 10);

				if (ni2.getY() == ni2.getToY() && ni2.getX() == ni2.getToX())
				{
					ni2.cnt = 0;
					ni2.setMoveAni(0); //�̵� off
					ni2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (ni2.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni2.cnt]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				ni2.cnt++;
				if (ni2.cnt == 3)
				{
					ni2.cnt = 0;
					ni2.setAtkAni(0);//���� off
				}
			}
			else if (ni2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, ni2.getX(), ni2.getY(), ni2.getX() + 60, ni2.getY() + 60);
			}
			else if (ni2.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				ni2.cnt = 0;
				ni2.setAblAni(0);//�ɷ� off
				//������
				p1.setTurn(1);
				p2.setTurn(0);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
				TransparentBlt(mem1dc, ni2.getX(), ni2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
			}
		}

		//��Ʈ
		if (gh2.getX() != 0 && gh2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (gh2.killedBy == 0)
			{
				if (gh2.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
				}
				else if (gh2.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					gh2.cnt++;
					if (gh2.cnt == 5)
						gh2.cnt = 3;
					//��ġ����
					gh2.setY(gh2.getY() + (gh2.getToY() - tmpY) / 10);
					gh2.setX(gh2.getX() + (gh2.getToX() - tmpX) / 10);

					if (gh2.getY() == gh2.getToY() && gh2.getX() == gh2.getToX())
					{
						gh2.cnt = 0;
						gh2.setMoveAni(0); //�̵� off
						if (gh2.getY() == b.getY()[0])	//��Ʈ�� ������� ���� ������ �� �ɷ� �ߵ��Ѵ�.
						{
							gh2.setAblTurn(1);//�ɷ��� on
							gh2.cnt = 6;
						}
						else
						{
							//������
							p2.setTurn(0);
							p1.setTurn(1);
						}
					}
				}
				else if (gh2.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					gh2.cnt++;
					if (gh2.cnt == 3)
					{
						gh2.cnt = 0;
						gh2.setAtkAni(0);//���� off
					}
				}
				else if (gh2.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh2.getX(), gh2.getY(), gh2.getX() + 60, gh2.getY() + 60);
				}
				else if (gh2.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[gh2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
					if (gh2.cnt == 8)
					{
						b.malPos[b.posToIndex(gh2.getY())][b.posToIndex(gh2.getX())] = 0;
						gh2.setY(b.getY()[8]);
						gh2.setX(b.getX()[3]);
						b.malPos[b.posToIndex(gh2.getY())][b.posToIndex(gh2.getX())] = 14;
						gh2.aniTmp = 1;
					}
					if (gh2.aniTmp)
					{
						--gh2.cnt;
						if (gh2.cnt == 5)
						{
							gh2.cnt = 0;
							gh2.aniTmp = 0;
							gh2.setAblAni(0);//�ɷ� off
							//������
							p2.setTurn(0);
							p1.setTurn(1);
						}
					}
					else
						gh2.cnt++;
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, ghBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 48, 48, RGB(255, 255, 255));	//��Ʈ �׸���
				}
			}
			else if (gh2.killedBy == 1)	//��Ʈ=>������
			{
				if (gh2.getX() != 0 && gh2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
				{
					if (gh2.getSelect() == 1)//����on
					{
						b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
					}
					else if (gh2.getMoveAni() == 1)	//�̵� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi2.cnt]);
						TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						//�̵� ����
						wi2.cnt++;
						if (wi2.cnt == 12)
						{
							//��ġ����
							gh2.setY(gh2.getToY());
							gh2.setX(gh2.getToX());
						}
						if (wi2.cnt == 15)
						{
							wi2.cnt = 0;
							gh2.setMoveAni(0); //�̵� off
							gh2.setAblTurn(1);//�ɷ��� on
						}
					}
					else if (gh2.getAblTurn() == 1)	//�ɷ��� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
						oldPen = (HPEN)SelectObject(mem1dc, hPen);
						Rectangle(mem1dc, gh2.getX(), gh2.getY(), gh2.getX() + 60, gh2.getY() + 60);
					}
					else if (gh2.getAblAni() == 1)	//�ɷ� on
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[wi2.cnt]);
						TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
						//�̵� ����
						wi2.cnt++;
						if (wi2.cnt == 12)
						{
							//��ġ����
							gh2.setY(gh2.getToY());
							gh2.setX(gh2.getToX());

							if (gh2.cngMal == 12)
							{
								re2.setY(re2.getToY());
								re2.setX(re2.getToX());
							}
							else if (gh2.cngMal == 13)
							{
								ni2.setY(ni2.getToY());
								ni2.setX(ni2.getToX());
							}
							else if (gh2.cngMal == 11)
							{
								wi2.setY(wi2.getToY());
								wi2.setX(wi2.getToX());
							}
							else if (gh2.cngMal == 15)
							{
								wa2.setY(wa2.getToY());
								wa2.setX(wa2.getToX());
							}
							else if (gh2.cngMal == 16)
							{
								de2.setY(de1.getToY());
								de2.setX(de1.getToX());
							}
							else if (gh2.cngMal == 17)
							{
								kn2.setY(kn2.getToY());
								kn2.setX(kn2.getToX());
							}
						}
						if (wi2.cnt == 15)
						{
							wi2.cnt = 0;
							gh2.setAblAni(0);//�ɷ� off
							//������
							p2.setTurn(0);
							p1.setTurn(1);
						}
					}
					else //����x,�̵�x,����x,�ɷ�x
					{
						oldBit2 = (HBITMAP)SelectObject(mem2dc, wiBit[0]);
						TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 40, 40, RGB(255, 255, 255));	//������ �׸���
					}
				}
			}
			else if (gh2.killedBy == 2)	//��Ʈ-���
			{
				if (gh2.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
				}
				else if (gh2.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[4]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					//�̵� ����
					//��ġ����
					gh2.setY(gh2.getY() + (gh2.getToY() - tmpY) / 10);
					gh2.setX(gh2.getX() + (gh2.getToX() - tmpX) / 10);

					if (gh2.getY() == gh2.getToY() && gh2.getX() == gh2.getToX())
					{
						re2.cnt = 0;
						gh2.setMoveAni(0); //�̵� off
						gh2.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh2.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					re2.cnt++;
					if (re2.cnt == 3)
					{
						re2.cnt = 0;
						gh2.setAtkAni(0);//���� off
					}
				}
				else if (gh2.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh2.getX(), gh2.getY(), gh2.getX() + 60, gh2.getY() + 60);
				}
				else if (gh2.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, reBit[re2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 0, 0, 70, 75, RGB(255, 255, 255));	//��� �׸���
					re2.cnt++;
					if (re2.cnt == 3)
					{
						re2.cnt = 0;
						gh2.setAblAni(0);//�ɷ� off
						//������
						p2.setTurn(0);
						p1.setTurn(1);
					}
				}
			}
			else if (gh2.killedBy == 3)//��Ʈ-����
			{
				if (gh2.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				}
				else if (gh2.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					//�̵� ����
					ni2.cnt++;
					ni2.cnt %= 9;
					//��ġ����
					gh2.setY(gh2.getY() + (gh2.getToY() - tmpY) / 10);
					gh2.setX(gh2.getX() + (gh2.getToX() - tmpX) / 10);

					if (gh2.getY() == gh2.getToY() && gh2.getX() == gh2.getToX())
					{
						ni2.cnt = 0;
						gh2.setMoveAni(0); //�̵� off
						gh2.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh2.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[ni2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					ni2.cnt++;
					if (ni2.cnt == 3)
					{
						ni2.cnt = 0;
						gh2.setAtkAni(0);//���� off
					}
				}
				else if (gh2.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh2.getX(), gh2.getY(), gh2.getX() + 60, gh2.getY() + 60);
				}
				else if (gh2.getAblAni() == 1)	//�ɷ� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
					ni2.cnt = 0;
					gh2.setAblAni(0);//�ɷ� off
					//������
					p2.setTurn(0);
					p1.setTurn(1);
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, niBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 140, 140, RGB(255, 255, 255));	//���� �׸���
				}
			}
			else if (gh2.killedBy == 5)//��Ʈ-����
			{
				if (gh2.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				}
				else if (gh2.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
					//�̵� ����
					if (wa2.cnt < 2)
						wa2.cnt++;
					//��ġ����
					gh2.setY(gh2.getY() + (gh2.getToY() - tmpY) / 10);
					gh2.setX(gh2.getX() + (gh2.getToX() - tmpX) / 10);
					if (gh2.getY() == tmpY + (gh2.getToY() - tmpY) * 8 / 10 && gh2.getX() == tmpX + (gh2.getToX() - tmpX) * 8 / 10)
					{
						wa2.cnt = 4;
					}
					else if (gh2.getY() == gh2.getToY() && gh2.getX() == gh2.getToX())
					{
						wa2.cnt = 0;
						gh2.setMoveAni(0); //�̵� off
						gh2.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh2.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
					if (wa2.cnt < 3)
					{
						wa2.cnt++;
					}
					else if (wa2.cnt == 3)
					{
						wa2.cnt = 5;
					}
					else if (wa2.cnt == 5)
					{
						wa2.cnt = 6;
					}
					else if (wa2.cnt == 6)
					{
						wa2.cnt = 0;
						gh2.setAtkAni(0);//���� off
					}
				}
				else if (gh2.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
					gh2.waAbillity(b, p1);
					//������
					gh2.setAblTurn(0);
					p2.setTurn(0);
					p1.setTurn(1);
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				}
			}
			else if (gh2.killedBy == 7)//��Ʈ-���
			{
				if (gh2.getSelect() == 1)//����on
				{
					b.moveable(hPen, oldPen, mem1dc, gh2, b, p1);
					oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				}
				else if (gh2.getMoveAni() == 1)	//�̵� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
					kn2.cnt++;
					kn2.cnt %= 4;
					//��ġ����
					gh2.setY(gh2.getY() + (gh2.getToY() - tmpY) / 10);
					gh2.setX(gh2.getX() + (gh2.getToX() - tmpX) / 10);

					if (gh2.getY() == gh2.getToY() && gh2.getX() == gh2.getToX())
					{
						kn2.cnt = 0;
						gh2.setMoveAni(0); //�̵� off
						gh2.setAblTurn(1);//�ɷ��� on
					}
				}
				else if (gh2.getAtkAni() == 1) //���� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn2.cnt]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
					kn2.cnt += 4;
					if (kn2.cnt == 9)
					{
						kn2.cnt = 0;
						gh2.setAtkAni(0);//���� off
					}
					kn2.cnt -= 3;
				}
				else if (gh2.getAblTurn() == 1)	//�ɷ��� on
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, gh2.getX(), gh2.getY(), gh2.getX() + 60, gh2.getY() + 60);
				}
				else //����x,�̵�x,����x,�ɷ�x
				{
					oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
					TransparentBlt(mem1dc, gh2.getX(), gh2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				}
			}
		}

		//����
		if (wa2.getX() != 0 && wa2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (wa2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, wa2, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, wa2.getX(), wa2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
			else if (wa2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa2.cnt]);
				TransparentBlt(mem1dc, wa2.getX(), wa2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				//�̵� ����
				if (wa2.cnt < 2)
					wa2.cnt++;
				//��ġ����
				wa2.setY(wa2.getY() + (wa2.getToY() - tmpY) / 10);
				wa2.setX(wa2.getX() + (wa2.getToX() - tmpX) / 10);
				if (wa2.getY() == tmpY + (wa2.getToY() - tmpY) * 8 / 10 && wa2.getX() == tmpX + (wa2.getToX() - tmpX) * 8 / 10)
				{
					wa2.cnt = 4;
				}
				else if (wa2.getY() == wa2.getToY() && wa2.getX() == wa2.getToX())
				{
					wa2.cnt = 0;
					wa2.setMoveAni(0); //�̵� off
					wa2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (wa2.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[wa2.cnt]);
				TransparentBlt(mem1dc, wa2.getX(), wa2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				if (wa2.cnt < 3)
				{
					wa2.cnt++;
				}
				else if (wa2.cnt == 3)
				{
					wa2.cnt = 5;
				}
				else if (wa2.cnt == 5)
				{
					wa2.cnt = 6;
				}
				else if (wa2.cnt == 6)
				{
					wa2.cnt = 0;
					wa2.setAtkAni(0);//���� off
				}
			}
			else if (wa2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, wa2.getX(), wa2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
				wa2.abillity(b,p1);
				//������
				wa2.setAblTurn(0);
				p1.setTurn(1);
				p2.setTurn(0);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, waBit[0]);
				TransparentBlt(mem1dc, wa2.getX(), wa2.getY(), 60, 60, mem2dc, 10, 10, 80, 80, RGB(255, 255, 255));	//���� �׸���
			}
		}

		//�����
		if (de2.getX() != 0 && de2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (de2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, de2, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
				TransparentBlt(mem1dc, de2.getX(), de2.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
			}
			else if (de2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[de2.cnt]);
				TransparentBlt(mem1dc, de2.getX(), de2.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				if (de2.cnt < 2)
					de2.cnt++;
				//��ġ����
				de2.setY(de2.getY() + (de2.getToY() - tmpY) / 10);
				de2.setX(de2.getX() + (de2.getToX() - tmpX) / 10);

				if (de2.getY() == de2.getToY() && de2.getX() == de2.getToX())
				{
					de2.cnt = 0;
					de2.setMoveAni(0); //�̵� off
					de2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (de2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
				TransparentBlt(mem1dc, de2.getX(), de2.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, de2.getX(), de2.getY(), de2.getX() + 60, de2.getY() + 60);
			}
			else if (de2.getAblAni() == 1)	//�ɷ� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[de2.cnt]);
				TransparentBlt(mem1dc, de2.getX(), de2.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
				if (de2.cnt < 2)
					de2.cnt++;
				//��ġ����
				de2.setY(de2.getY() + (de2.getToY() - tmpY) / 10);
				de2.setX(de2.getX() + (de2.getToX() - tmpX) / 10);

				if (de2.getY() == de2.getToY() && de2.getX() == de2.getToX())
				{
					de2.cnt = 0;
					de2.setAblAni(0);//�ɷ� off
					//������
					p1.setTurn(1);
					p2.setTurn(0);
				}
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, deBit[0]);
				TransparentBlt(mem1dc, de2.getX(), de2.getY(), 60, 60, mem2dc, 10, 10, 120, 120, RGB(255, 255, 255));	//����� �׸���
			}
		}

		//���
		if (kn2.getX() != 0 && kn2.getY() != 0)//�� ��ġ�� 0�� �ƴ� �� = ���� �� ���� ��
		{
			if (kn2.getSelect() == 1)//����on
			{
				b.moveable(hPen, oldPen, mem1dc, kn2, b, p1);
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, kn2.getX(), kn2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
			else if (kn2.getMoveAni() == 1)	//�̵� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn2.cnt]);
				TransparentBlt(mem1dc, kn2.getX(), kn2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn2.cnt++;
				kn2.cnt %= 4;
				//��ġ����
				kn2.setY(kn2.getY() + (kn2.getToY() - tmpY) / 10);
				kn2.setX(kn2.getX() + (kn2.getToX() - tmpX) / 10);

				if (kn2.getY() == kn2.getToY() && kn2.getX() == kn2.getToX())
				{
					kn2.cnt = 0;
					kn2.setMoveAni(0); //�̵� off
					kn2.setAblTurn(1);//�ɷ��� on
				}
			}
			else if (kn2.getAtkAni() == 1) //���� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[kn2.cnt]);
				TransparentBlt(mem1dc, kn2.getX(), kn2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				kn2.cnt += 4;
				if (kn2.cnt == 9)
				{
					kn2.cnt = 0;
					kn2.setAtkAni(0);//���� off
				}
				kn2.cnt -= 3;
			}
			else if (kn2.getAblTurn() == 1)	//�ɷ��� on
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, kn2.getX(), kn2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
				hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));	//ĭ�� ����׵θ� �׸���
				oldPen = (HPEN)SelectObject(mem1dc, hPen);
				Rectangle(mem1dc, kn2.getX(), kn2.getY(), kn2.getX() + 60, kn2.getY() + 60);
			}
			else //����x,�̵�x,����x,�ɷ�x
			{
				oldBit2 = (HBITMAP)SelectObject(mem2dc, knBit[0]);
				TransparentBlt(mem1dc, kn2.getX(), kn2.getY(), 60, 60, mem2dc, 15, 15, 70, 70, RGB(255, 255, 255));	//��� �׸���
			}
		}

		oldBit2 = (HBITMAP)SelectObject(mem2dc, caBit);
		TransparentBlt(mem1dc, b.getX()[3], b.getY()[9] - 30, 60, 90, mem2dc, 0, 0, 674, 867, RGB(255, 255, 255));

		if (ca2.getLife() == 1)
		{
			oldBit2 = (HBITMAP)SelectObject(mem2dc, fiBit);
			TransparentBlt(mem1dc, b.getX()[3], b.getY()[9], 60, 60, mem2dc, 0, 0, 260, 260, RGB(255, 255, 255));		//�� �׸���
		}

		SelectObject(mem1dc, oldPen);
		DeleteObject(hPen);

		SelectObject(mem2dc, oldBit2);
		DeleteDC(mem2dc);
		SelectObject(mem1dc, oldBit1);
		DeleteDC(mem1dc);

		ReleaseDC(hWnd, hdc);
		InvalidateRgn(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		mem1dc = CreateCompatibleDC(hdc);
		oldBit1 = (HBITMAP)SelectObject(mem1dc, hBit);
		BitBlt(hdc, 0, 0, winW, winH, mem1dc, 0, 0, SRCCOPY);

		SelectObject(mem1dc, oldBit1);
		DeleteDC(mem1dc);

		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (p1.getTurn() == 1)//p1�� ������ ��
			for (int iy = 0; iy < 10; ++iy)
				for (int ix = 0; ix < 7; ++ix)
				{
					if (my > b.getY()[iy] && my < b.getY()[iy] + 60 && mx>b.getX()[ix] && mx < b.getX()[ix] + 60) //ĭ�� Ŭ������ ��
					{
						if (wi1.getAblTurn() == 0 && re1.getAblTurn() == 0 && ni1.getAblTurn() == 0 && gh1.getAblTurn() == 0 &&
							wa1.getAblTurn() == 0 && de1.getAblTurn() == 0 && kn1.getAblTurn() == 0 &&
							wi1.getSelect() == 0 && re1.getSelect() == 0 && ni1.getSelect() == 0 && gh1.getSelect() == 0 &&
							wa1.getSelect() == 0 && de1.getSelect() == 0 && kn1.getSelect() == 0 )	//�� ���� �� �ɷ� �����, �������� �ƴҶ�
						{
							if (wa2.wiCannotMove==0&& gh2.wiCannotMove == 0 && b.malPos[iy][ix] == 1) // �� ĭ�� �����簡 ���� ��
							{
								wi1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.reCannotMove == 0 && gh2.reCannotMove == 0 && b.malPos[iy][ix] == 2) // �� ĭ�� ����� ���� ��
							{
								re1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.niCannotMove == 0 && gh2.niCannotMove == 0 && b.malPos[iy][ix] == 3) // �� ĭ�� ���ڰ� ���� ��
							{
								ni1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.ghCannotMove == 0 && gh2.ghCannotMove == 0 && b.malPos[iy][ix] == 4) // �� ĭ�� ��Ʈ�� ���� ��
							{
								gh1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.waCannotMove == 0 && gh2.waCannotMove == 0 && b.malPos[iy][ix] == 5) // �� ĭ�� ���簡 ���� ��
							{
								wa1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.deCannotMove == 0 && gh2.deCannotMove == 0 && b.malPos[iy][ix] == 6) // �� ĭ�� ������� ���� ��
							{
								de1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa2.knCannotMove == 0 && gh2.knCannotMove == 0 && b.malPos[iy][ix] == 7) // �� ĭ�� ��簡 ���� ��
							{
								kn1.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
						}
						if (b.malPos[iy][ix] == 0 || b.malPos[iy][ix] > 10)	// �̵��� �� �Ʊ�Ŭ������
						{
							//������ �̵�
							if (wi1.getSelect() == 1 && b.malPos[iy][ix] != 16 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//�����簡 ���õ��� �� �׸��� �̵����� ���� �� 
							{
								if (iy == 9 && ix == 3)
								{
									atkCastle(hWnd, ca2, wi1, b, p1, itx, ity);
								}
								else
								{
									wi1.setSelect(0);// ���� ���� ǥ�� off
									wi1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
									if (b.malPos[iy][ix] > 10)//�� ĭ�� ���� ���� ��
									{
										//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
										//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
										if (b.malPos[iy][ix] == 11)
										{
											wi2.setY(0);
											wi2.setX(0);
										}
										else if (b.malPos[iy][ix] == 12)
										{
											re2.setY(0);
											re2.setX(0);
										}
										else if (b.malPos[iy][ix] == 13)
										{
											ni2.setY(0);
											ni2.setX(0);
										}
										else if (b.malPos[iy][ix] == 14)
										{
											gh2.setY(b.getY()[8]);
											gh2.setX(b.getX()[3]);
											gh2.killedBy = 1;
											b.malPos[8][3] = 14;
										}
										else if (b.malPos[iy][ix] == 15)
										{
											wa2.setY(0);
											wa2.setX(0);
										}
										else if (b.malPos[iy][ix] == 17)
										{
											kn2.setY(0);
											kn2.setX(0);
										}
									}
									//������ ����
									wi1.setToY(b.getY()[iy]);
									wi1.setToX(b.getX()[ix]);
									//����ȣ ������ġ �ٲٱ�
									b.malPos[ity][itx] = 0;
									b.malPos[iy][ix] = 1;
									ity = iy;	itx = ix;
								}
							}
							//��� �̵�
							else if (re1.getSelect() == 1 && b.malPos[iy][ix] != 16 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
								if (iy == 9 && ix == 3)
								{
									atkCastle(hWnd, ca2, re1, b, p1, itx, ity);
								}
								else
								{
									re1.setSelect(0);// ���� ���� ǥ�� off
									re1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
									tmpY = re1.getY();
									tmpX = re1.getX();
									if (b.malPos[iy][ix] > 10)//�� ĭ�� ���� ���� ��
									{
										re1.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
										//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
										if (b.malPos[iy][ix] == 11)
										{
											wi2.setY(0);
											wi2.setX(0);
										}
										else if (b.malPos[iy][ix] == 12)
										{
											re2.setY(0);
											re2.setX(0);
										}
										else if (b.malPos[iy][ix] == 13)
										{
											ni2.setY(0);
											ni2.setX(0);
										}
										else if (b.malPos[iy][ix] == 14)
										{
											gh2.setY(b.getY()[8]);
											gh2.setX(b.getX()[3]);
											gh2.killedBy = 2;
											b.malPos[8][3] = 14;
										}
										else if (b.malPos[iy][ix] == 15)
										{
											wa2.setY(0);
											wa2.setX(0);
										}
										else if (b.malPos[iy][ix] == 17)
										{
											kn2.setY(0);
											kn2.setX(0);
										}
									}
									//������ ����
									re1.setToY(b.getY()[iy]);
									re1.setToX(b.getX()[ix]);
									//����ȣ ������ġ �ٲٱ�
									b.malPos[ity][itx] = 0;
									b.malPos[iy][ix] = 2;
									ity = iy;	itx = ix;
								}
							}
							//���� �̵�
							else if (ni1.getSelect() == 1 && b.malPos[iy][ix] != 16 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 9 && ix == 3)
							{
								atkCastle(hWnd, ca2, ni1, b, p1, itx, ity);
							}
							else
							{
								ni1.setSelect(0);// ���� ���� ǥ�� off
								ni1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = ni1.getY();
								tmpX = ni1.getX();
								if (b.malPos[iy][ix] > 10)//�� ĭ�� ���� ���� ��
								{
									ni1.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 11)
									{
										wi2.setY(0);
										wi2.setX(0);
									}
									else if (b.malPos[iy][ix] == 12)
									{
										re2.setY(0);
										re2.setX(0);
									}
									else if (b.malPos[iy][ix] == 13)
									{
										ni2.setY(0);
										ni2.setX(0);
									}
									else if (b.malPos[iy][ix] == 14)
									{
										gh2.setY(b.getY()[8]);
										gh2.setX(b.getX()[3]);
										gh2.killedBy = 3;
										b.malPos[8][3] = 14;
									}
									else if (b.malPos[iy][ix] == 15)
									{
										wa2.setY(0);
										wa2.setX(0);
									}
									else if (b.malPos[iy][ix] == 17)
									{
										kn2.setY(0);
										kn2.setX(0);
									}
								}
								//������ ����
								ni1.setToY(b.getY()[iy]);
								ni1.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 3;
								ity = iy;	itx = ix;
							}
								
							}
							//��Ʈ �̵�
							else if (gh1.getSelect() == 1 && b.malPos[iy][ix] == 0 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 9 && ix == 3)
							{
								atkCastle(hWnd, ca2, gh1, b, p1, itx, ity);
							}
							else
							{
								gh1.setSelect(0);// ���� ���� ǥ�� off
								gh1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = gh1.getY();
								tmpX = gh1.getX();

								//������ ����
								gh1.setToY(b.getY()[iy]);
								gh1.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 4;
								ity = iy;	itx = ix;

							}
							}
							//���� �̵�
							else if (wa1.getSelect() == 1 && b.malPos[iy][ix] != 16 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 9 && ix == 3)
							{
								atkCastle(hWnd, ca2, wa1, b, p1, itx, ity);
							}
							else
							{
								wa1.setSelect(0);// ���� ���� ǥ�� off
								wa1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = wa1.getY();
								tmpX = wa1.getX();
								if (b.malPos[iy][ix] > 10)//�� ĭ�� ���� ���� ��
								{
									wa1.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 11)
									{
										wi2.setY(0);
										wi2.setX(0);
									}
									else if (b.malPos[iy][ix] == 12)
									{
										re2.setY(0);
										re2.setX(0);
									}
									else if (b.malPos[iy][ix] == 13)
									{
										ni2.setY(0);
										ni2.setX(0);
									}
									else if (b.malPos[iy][ix] == 14)
									{
										gh2.setY(b.getY()[8]);
										gh2.setX(b.getX()[3]);
										gh2.killedBy = 5;
										b.malPos[8][3] = 14;
									}
									else if (b.malPos[iy][ix] == 15)
									{
										wa2.setY(0);
										wa2.setX(0);
									}
									else if (b.malPos[iy][ix] == 17)
									{
										kn2.setY(0);
										kn2.setX(0);
									}
								}

								//������ ����
								wa1.setToY(b.getY()[iy]);
								wa1.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 5;
								ity = iy;	itx = ix;
							}
			
							}
							//����� �̵�
							else if (de1.getSelect() == 1 && b.malPos[iy][ix] == 0 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
								de1.setSelect(0);// ���� ���� ǥ�� off
								de1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = de1.getY();
								tmpX = de1.getX();
								//������ ����
								de1.setToY(b.getY()[iy]);
								de1.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 6;
								ity = iy;	itx = ix;
							}
							//��� �̵�
							else if (kn1.getSelect() == 1 && b.malPos[iy][ix] != 16 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 9 && ix == 3)
							{
								atkCastle(hWnd, ca2, kn1, b, p1, itx, ity);
							}
							else
							{
								kn1.setSelect(0);// ���� ���� ǥ�� off
								kn1.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = kn1.getY();
								tmpX = kn1.getX();
								if (b.malPos[iy][ix] > 10)//�� ĭ�� ���� ���� ��
								{
									kn1.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 11)
									{
										wi2.setY(0);
										wi2.setX(0);
									}
									else if (b.malPos[iy][ix] == 12)
									{
										re2.setY(0);
										re2.setX(0);
									}
									else if (b.malPos[iy][ix] == 13)
									{
										ni2.setY(0);
										ni2.setX(0);
									}
									else if (b.malPos[iy][ix] == 14)
									{
										gh2.setY(b.getY()[8]);
										gh2.setX(b.getX()[3]);
										gh2.killedBy = 7;
										b.malPos[8][3] = 14;
									}
									else if (b.malPos[iy][ix] == 15)
									{
										wa2.setY(0);
										wa2.setX(0);
									}
									else if (b.malPos[iy][ix] == 17)
									{
										kn2.setY(0);
										kn2.setX(0);
									}
								}
								//������ ����
								kn1.setToY(b.getY()[iy]);
								kn1.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 7;
								ity = iy;	itx = ix;
							}
	
							}
						}
						
						//������ �ɷ�
						if (wi1.getAblTurn() == 1) //�ɷ� ��on
						{
							wi1.setAblTurn(0); //�ɷ��� off
							wi1.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] > 1 && b.malPos[iy][ix] <= 7)//�Ʊ� ���� Ŭ������ ��
								wi1.abillity(re1, ni1, gh1, wa1, de1, kn1, b, ix, iy, itx, ity, p1);
							else
							{
								wi1.setAblAni(0);//�ɷ� off
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
						}
						//��� �ɷ�
						else if (re1.getAblTurn() == 1)
						{
							re1.setAblTurn(0); //�ɷ��� off
							re1.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� ��Ŭ��
								re1.abillity(wi2, re2, ni2, gh2, wa2, de2, kn2, b, ix, iy,p1);
							else
							{
								re1.setAblAni(0);//�ɷ� off
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
						}
						//���� �ɷ�
						else if (ni1.getAblTurn() == 1)
						{
							ni1.setAblTurn(0); //�ɷ��� off
							ni1.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
							{
								//ni1.knAbillity(b, ix, iy, tmpX, tmpY, wi1, re1, ni1, gh1, wa1, de1);
								ni1.setAblAni(0);//�ɷ� off
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
							else
							{
								ni1.setAblAni(0);//�ɷ� off
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
						}
						//��Ʈ �ɷ�
						else if (gh1.getAblTurn() == 1)
						{
							gh1.setAblTurn(0); //�ɷ��� off

							if (gh1.killedBy == 0)
							{
								gh1.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17)
									gh1.abillity(wi2, re2, ni2, gh2, wa2, de2, kn2, b, ix, iy, p1);
								else
								{
									gh1.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(0);
									p2.setTurn(1);
								}
							}
							if (gh1.killedBy == 11)//��Ʈ-������
							{
								gh1.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7&&b.malPos[iy][ix]!=4)//�Ʊ� ���� Ŭ������ ��
									gh1.wiAbillity(re1, ni1, wi1, wi1, de1, kn1, b, ix, iy, itx, ity, p1);
								else
								{
									gh1.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(0);
									p2.setTurn(1);
								}
							}
							if (gh1.killedBy == 12)//��Ʈ-���
							{
								gh1.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� ��Ŭ��
									gh1.abillity(wi2, re2, ni2, gh2, wa2, de2, kn2, b, ix, iy, p1);
								else
								{
									gh1.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(0);
									p2.setTurn(1);
								}
							}
							if (gh1.killedBy == 13)//��Ʈ-����
							{
								gh1.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
								{
									//ni1.knAbillity(b, ix, iy, tmpX, tmpY, wi1, re1, ni1, gh1, wa1, de1);
									gh1.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(0);
									p2.setTurn(1);
								}
								else
								{
									ni1.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(0);
									p2.setTurn(1);
								}
							}
							if (gh1.killedBy == 17)//��Ʈ-���
							{
								if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
								{
									gh1.knAbillity(b, ix, iy, tmpX, tmpY, wi1, re1, ni1, gh1, wa1, de1, p1);
								}
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
						}
						//���� �ɷ� = �нú�
						//����� �ɷ�
						else if (de1.getAblTurn() == 1)
						{
							de1.setAblTurn(0); //�ɷ��� off
							de1.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] == 0)
							{
								tmpY = de1.getY();
								tmpX = de1.getX();
								de1.abillity(b, ix, iy, itx, ity, tmpX, tmpY, p1, p2);
							}
							else
							{
								de1.setAblAni(0);//�ɷ� off
								//������
								p1.setTurn(0);
								p2.setTurn(1);
							}
						}
						//���ɷ�
						else if (kn1.getAblTurn() == 1)
						{
							kn1.setAblTurn(0); //�ɷ��� off
							//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
							{
								kn1.abillity(b, ix, iy, tmpX, tmpY, wi1, re1, ni1, gh1, wa1, de1,p1);
							}
								//������
								p1.setTurn(0);
								p2.setTurn(1);
						}
					}
				}
		else if (p2.getTurn() == 1)//p2 ������ ��
			for (int iy = 0; iy < 10; ++iy)
				for (int ix = 0; ix < 7; ++ix)
				{
					if (my > b.getY()[iy] && my < b.getY()[iy] + 60 && mx>b.getX()[ix] && mx < b.getX()[ix] + 60) //ĭ�� Ŭ������ ��
					{
						if (wi2.getAblTurn() == 0 && re2.getAblTurn() == 0 && ni2.getAblTurn() == 0 && gh2.getAblTurn() == 0 &&
							wa2.getAblTurn() == 0 && de2.getAblTurn() == 0 && kn2.getAblTurn() == 0 &&
							wi2.getSelect() == 0 && re2.getSelect() == 0 && ni2.getSelect() == 0 && gh2.getSelect() == 0 &&
							wa2.getSelect() == 0 && de2.getSelect() == 0 && kn2.getSelect() == 0)	//�� ���� �� �ɷ� �����, �������� �ƴҶ�
						{
							if (wa1.wiCannotMove == 0 && gh1.wiCannotMove == 0 && b.malPos[iy][ix] == 11) // �� ĭ�� �����簡 ���� ��
							{
								wi2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.reCannotMove == 0 && gh1.reCannotMove == 0 && b.malPos[iy][ix] == 12) // �� ĭ�� ����� ���� ��
							{
								re2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.niCannotMove == 0 && gh1.niCannotMove == 0 && b.malPos[iy][ix] == 13) // �� ĭ�� ���ڰ� ���� ��
							{
								ni2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.ghCannotMove == 0 && gh1.ghCannotMove == 0 && b.malPos[iy][ix] == 14) // �� ĭ�� ��Ʈ�� ���� ��
							{
								gh2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.waCannotMove == 0 && gh1.waCannotMove == 0 && b.malPos[iy][ix] == 15) // �� ĭ�� ���簡 ���� ��
							{
								wa2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.deCannotMove == 0 && gh1.deCannotMove == 0 && b.malPos[iy][ix] == 16) // �� ĭ�� ������� ���� ��
							{
								de2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
							else if (wa1.knCannotMove == 0 && gh1.knCannotMove == 0 && b.malPos[iy][ix] == 17) // �� ĭ�� ��簡 ���� ��
							{
								kn2.setSelect(1);// ���� ���� ǥ�� on
								ity = iy;	itx = ix;
							}
						}
						if (b.malPos[iy][ix] < 10)	// �̵��� �� �Ʊ�Ŭ������
						{
							//������ �̵�
							if (wi2.getSelect() == 1 && b.malPos[iy][ix] != 6 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//�����簡 ���õ��� �� �׸��� �̵����� ���� �� 
							{
								if (iy == 0 && ix == 3)
								{
									atkCastle(hWnd, ca1, wi2, b, p1, itx, ity);
								}
								else
								{
									wi2.setSelect(0);// ���� ���� ǥ�� off
									wi2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
									if (b.malPos[iy][ix] < 10 && b.malPos[iy][ix]>0)//�� ĭ�� ���� ���� ��
									{
										//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
										//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
										if (b.malPos[iy][ix] == 1)
										{
											wi1.setY(0);
											wi1.setX(0);
										}
										else if (b.malPos[iy][ix] == 2)
										{
											re1.setY(0);
											re1.setX(0);
										}
										else if (b.malPos[iy][ix] == 3)
										{
											ni1.setY(0);
											ni1.setX(0);
										}
										else if (b.malPos[iy][ix] == 4)
										{
											gh1.setY(b.getY()[1]);
											gh1.setX(b.getX()[3]);
											gh1.killedBy = 11;
											b.malPos[1][3] = 4;
										}
										else if (b.malPos[iy][ix] == 5)
										{
											wa1.setY(0);
											wa1.setX(0);
										}
										else if (b.malPos[iy][ix] == 7)
										{
											kn1.setY(0);
											kn1.setX(0);
										}
									}
									//������ ����
									wi2.setToY(b.getY()[iy]);
									wi2.setToX(b.getX()[ix]);
									//����ȣ ������ġ �ٲٱ�
									b.malPos[ity][itx] = 0;
									b.malPos[iy][ix] = 11;
									ity = iy;	itx = ix;
								}
		
							}
							//��� �̵�
							else if (re2.getSelect() == 1 && b.malPos[iy][ix] != 6 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
								if (iy == 0 && ix == 3)
								{
									atkCastle(hWnd, ca1, re2, b, p1, itx, ity);
								}
								else
								{
									re2.setSelect(0);// ���� ���� ǥ�� off
									re2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
									tmpY = re2.getY();
									tmpX = re2.getX();
									if (b.malPos[iy][ix] < 10 && b.malPos[iy][ix]>0)//�� ĭ�� ���� ���� ��
									{
										re2.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
										//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
										if (b.malPos[iy][ix] == 1)
										{
											wi1.setY(0);
											wi1.setX(0);
										}
										else if (b.malPos[iy][ix] == 2)
										{
											re1.setY(0);
											re1.setX(0);
										}
										else if (b.malPos[iy][ix] == 3)
										{
											ni1.setY(0);
											ni1.setX(0);
										}
										else if (b.malPos[iy][ix] == 4)
										{
											gh1.setY(b.getY()[1]);
											gh1.setX(b.getX()[3]);
											gh1.killedBy = 12;
											b.malPos[1][3] = 4;
										}
										else if (b.malPos[iy][ix] == 5)
										{
											wa1.setY(0);
											wa1.setX(0);
										}
										else if (b.malPos[iy][ix] == 7)
										{
											kn1.setY(0);
											kn1.setX(0);
										}
									}

									//������ ����
									re2.setToY(b.getY()[iy]);
									re2.setToX(b.getX()[ix]);
									//����ȣ ������ġ �ٲٱ�
									b.malPos[ity][itx] = 0;
									b.malPos[iy][ix] = 12;
									ity = iy;	itx = ix;
								}
		
							}
							//���� �̵�
							else if (ni2.getSelect() == 1 && b.malPos[iy][ix] != 6 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 0 && ix == 3)
							{
								atkCastle(hWnd, ca1, ni2, b, p1, itx, ity);
							}
							else
							{
								ni2.setSelect(0);// ���� ���� ǥ�� off
								ni2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = ni2.getY();
								tmpX = ni2.getX();
								if (b.malPos[iy][ix] < 10 && b.malPos[iy][ix]>0)//�� ĭ�� ���� ���� ��
								{
									ni2.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 1)
									{
										wi1.setY(0);
										wi1.setX(0);
									}
									else if (b.malPos[iy][ix] == 2)
									{
										re1.setY(0);
										re1.setX(0);
									}
									else if (b.malPos[iy][ix] == 3)
									{
										ni1.setY(0);
										ni1.setX(0);
									}
									else if (b.malPos[iy][ix] == 4)
									{
										gh1.setY(b.getY()[1]);
										gh1.setX(b.getX()[3]);
										gh1.killedBy = 13;
										b.malPos[1][3] = 4;
									}
									else if (b.malPos[iy][ix] == 5)
									{
										wa1.setY(0);
										wa1.setX(0);
									}
									else if (b.malPos[iy][ix] == 7)
									{
										kn1.setY(0);
										kn1.setX(0);
									}
								}
								//������ ����
								ni2.setToY(b.getY()[iy]);
								ni2.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 13;
								ity = iy;	itx = ix;
							}
						
							}
							//��Ʈ �̵�
							else if (gh2.getSelect() == 1 && b.malPos[iy][ix] == 0 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 0 && ix == 3)
							{
								atkCastle(hWnd, ca1, gh2, b, p1, itx, ity);
							}
							else
							{
								gh2.setSelect(0);// ���� ���� ǥ�� off
								gh2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = gh2.getY();
								tmpX = gh2.getX();
								//������ ����
								gh2.setToY(b.getY()[iy]);
								gh2.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 14;
								ity = iy;	itx = ix;
							}
	
							}
							//���� �̵�
							else if (wa2.getSelect() == 1 && b.malPos[iy][ix] != 6 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 0 && ix == 3)
							{
								atkCastle(hWnd, ca1, wa2, b, p1, itx, ity);
							}
							else
							{
								wa2.setSelect(0);// ���� ���� ǥ�� off
								wa2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = wa2.getY();
								tmpX = wa2.getX();
								if (b.malPos[iy][ix] < 10 && b.malPos[iy][ix]>0)//�� ĭ�� ���� ���� ��
								{
									wa2.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 1)
									{
										wi1.setY(0);
										wi1.setX(0);
									}
									else if (b.malPos[iy][ix] == 2)
									{
										re1.setY(0);
										re1.setX(0);
									}
									else if (b.malPos[iy][ix] == 3)
									{
										ni1.setY(0);
										ni1.setX(0);
									}
									else if (b.malPos[iy][ix] == 4)
									{
										gh1.setY(b.getY()[1]);
										gh1.setX(b.getX()[3]);
										gh1.killedBy = 15;
										b.malPos[1][3] = 4;
									}
									else if (b.malPos[iy][ix] == 5)
									{
										wa1.setY(0);
										wa1.setX(0);
									}
									else if (b.malPos[iy][ix] == 7)
									{
										kn1.setY(0);
										kn1.setX(0);
									}
								}

								//������ ����
								wa2.setToY(b.getY()[iy]);
								wa2.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 15;
								ity = iy;	itx = ix;
							}
							
							}
							//����� �̵�
							else if (de2.getSelect() == 1 && b.malPos[iy][ix] == 0 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
								de2.setSelect(0);// ���� ���� ǥ�� off
								de2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = de2.getY();
								tmpX = de2.getX();
								//������ ����
								de2.setToY(b.getY()[iy]);
								de2.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 16;
								ity = iy;	itx = ix;
							}
							//��� �̵�
							else if (kn2.getSelect() == 1 && b.malPos[iy][ix] != 6 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1)))	//����� ���õ��� �� �׸��� �̵����� ���� ��
							{
							if (iy == 0 && ix == 3)
							{
								atkCastle(hWnd, ca1, kn2, b, p1, itx, ity);
							}
							else
							{
								kn2.setSelect(0);// ���� ���� ǥ�� off
								kn2.setMoveAni(1);//���� �̵��ϴ� �ִϸ��̼� on
								tmpY = kn2.getY();
								tmpX = kn2.getX();
								if (b.malPos[iy][ix] < 10 && b.malPos[iy][ix]>0)//�� ĭ�� ���� ���� ��
								{
									kn2.setAtkAni(1);//���� �����ϴ� �ִϸ��̼� on(������x,�����x)
									//�� ���� ���ŵ� => ��ġ 0,0���� �̵� 
									if (b.malPos[iy][ix] == 1)
									{
										wi1.setY(0);
										wi1.setX(0);
									}
									else if (b.malPos[iy][ix] == 2)
									{
										re1.setY(0);
										re1.setX(0);
									}
									else if (b.malPos[iy][ix] == 3)
									{
										ni1.setY(0);
										ni1.setX(0);
									}
									else if (b.malPos[iy][ix] == 4)
									{
										gh1.setY(b.getY()[1]);
										gh1.setX(b.getX()[3]);
										gh1.killedBy = 17;
										b.malPos[1][3] = 4;
									}
									else if (b.malPos[iy][ix] == 5)
									{
										wa1.setY(0);
										wa1.setX(0);
									}
									else if (b.malPos[iy][ix] == 7)
									{
										kn1.setY(0);
										kn1.setX(0);
									}
								}
								//������ ����
								kn2.setToY(b.getY()[iy]);
								kn2.setToX(b.getX()[ix]);
								//����ȣ ������ġ �ٲٱ�
								b.malPos[ity][itx] = 0;
								b.malPos[iy][ix] = 17;
								ity = iy;	itx = ix;
							}
	
							}
						}

						//������ �ɷ�
						if (wi2.getAblTurn() == 1) //�ɷ� ��on
						{
							wi2.setAblTurn(0); //�ɷ��� off
							wi2.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] > 10)//�Ʊ� ���� Ŭ������ ��
								wi2.abillity(re2, ni2, gh2, wa2, de2, kn2, b, ix, iy, itx, ity, p1);
							else
							{
								wi2.setAblAni(0);//�ɷ� off
								//������
								p2.setTurn(0);
								p1.setTurn(1);
							}
						}
						//��� �ɷ�
						else if (re2.getAblTurn() == 1)
						{
							re2.setAblTurn(0); //�ɷ��� off
							re2.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� ��Ŭ��
								re2.abillity(wi1, re1, ni1, gh1, wa1, de1, kn1, b, ix, iy,p1);
							else
							{
								re2.setAblAni(0);//�ɷ� off
								//������
								p2.setTurn(0);
								p1.setTurn(1);
							}
						}
						//���� �ɷ�
						else if (ni2.getAblTurn() == 1)
						{
							ni2.setAblTurn(0); //�ɷ��� off
							ni2.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
							{
								ni2.setAblAni(0);//�ɷ� off
								//������
								p2.setTurn(0);
								p1.setTurn(1);
							}
							else
							{
								ni2.setAblAni(0);//�ɷ� off
								//������
								p2.setTurn(0);
								p1.setTurn(1);
							}
						}
						//��Ʈ �ɷ�
						else if (gh2.getAblTurn() == 1)
						{
							gh2.setAblTurn(0); //�ɷ��� off

							if (gh2.killedBy == 0)
							{
								gh2.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7)
									gh2.abillity(wi1, re1, ni1, gh1, wa1, de1, kn1, b, ix, iy, p1);
								else
								{
									gh2.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(1);
									p2.setTurn(0);
								}
							}
							if (gh2.killedBy == 11)//��Ʈ-������
							{
								gh2.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <=17 && b.malPos[iy][ix] != 14)//�Ʊ� ���� Ŭ������ ��
									gh2.wiAbillity(re2, ni2, wi2, wi2, de2, kn2, b, ix, iy, itx, ity, p1);
								else
								{
									gh2.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(1);
									p2.setTurn(0);
								}
							}
							if (gh2.killedBy == 12)//��Ʈ-���
							{
								gh2.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 1 && b.malPos[iy][ix] <= 7 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� ��Ŭ��
									gh2.abillity(wi1, re1, ni1, gh1, wa1, de1, kn1, b, ix, iy, p1);
								else
								{
									gh2.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(1);
									p2.setTurn(0);
								}
							}
							if (gh2.killedBy == 13)//��Ʈ-����
							{
								gh2.setAblAni(1);//�ɷ»��ִ�on

								if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
								{
									//ni1.knAbillity(b, ix, iy, tmpX, tmpY, wi1, re1, ni1, gh1, wa1, de1);
									gh2.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(1);
									p2.setTurn(0);
								}
								else
								{
									gh2.setAblAni(0);//�ɷ� off
									//������
									p1.setTurn(1);
									p2.setTurn(0);
								}
							}
							if (gh2.killedBy == 17)//��Ʈ-���
							{
								if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
									((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
										(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
										(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
								{
									gh2.knAbillity(b, ix, iy, tmpX, tmpY, wi2, re2, ni2, gh2, wa2, de2, p1);
								}
								//������
								p1.setTurn(1);
								p2.setTurn(0);
							}
						}
						//���� �ɷ� = �нú�
						//����� �ɷ�
						else if (de2.getAblTurn() == 1)
						{
							de2.setAblTurn(0); //�ɷ��� off
							de2.setAblAni(1);//�ɷ»��ִ�on

							if (b.malPos[iy][ix] == 0)
							{
								tmpY = de2.getY();
								tmpX = de2.getX();
								de2.abillity(b, ix, iy, itx, ity, tmpX, tmpY, p1, p2);
							}
							else
							{
								de2.setAblAni(0);//�ɷ� off
								//������
								p2.setTurn(0);
								p1.setTurn(1);
							}
						}
						//���ɷ�
						else if (kn2.getAblTurn() == 1)
						{
							kn2.setAblTurn(0); //�ɷ��� off
							//�ɷ»��ִ�on

							if (b.malPos[iy][ix] >= 11 && b.malPos[iy][ix] <= 17 &&
								((iy == ity - 1 && ix == itx) || (iy == ity + 1 && ix == itx) ||
									(iy == ity && ix == itx - 1) || (iy == ity && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx - 1) || (iy == ity + 1 && ix == itx + 1) ||
									(iy == ity - 1 && ix == itx + 1) || (iy == ity + 1 && ix == itx - 1)))	//�ɷ¹ݰ泻�� �Ʊ�Ŭ��
							{
								kn2.abillity(b, ix, iy, tmpX, tmpY, wi2, re2, ni2, gh2, wa2, de2, p1);
							}
							//������
							p2.setTurn(0);
							p1.setTurn(1);
						}
					}
				}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
