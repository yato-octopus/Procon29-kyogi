#include "Interrupt.h"

void Interrupt::interruptManager(void)
{
	backTurn();
	goTurn();
	prefetchingInfo();
	Research();
}

void Interrupt::backTurn(void)
{
	//1�^�[���߂鏈��
	//�^�[�����Ǘ����Ă���ϐ��̒l�����炷�E�E�H
}

void Interrupt::goTurn(void)
{
	//1�^�[���i��

}

void Interrupt::prefetchingInfo(void)
{
	//�ǂ��܂Ő�ǂނ��̐���ǂݍ���
	//Map�N���X�̒������������E�E�E�H
}

void Interrupt::Research(void)
{
	//�����^�[���ɂ����ĒT���A���S���Y�����ēx������
}