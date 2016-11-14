#include "stdafx.h"
#include "game.h"
#include "RenderTarget.h"

//-----------------------------------------------------------------------------
// �O���[�o���ϐ��B
//-----------------------------------------------------------------------------
Game* game;		
CRenderTarget* rendertarget;
/*!-----------------------------------------------------------------------------
*@brief	���C�g���X�V�B
-----------------------------------------------------------------------------*/
void UpdateLight()
{
	game->UpdateLight();
}
//-----------------------------------------------------------------------------
// Name: �Q�[�����������B
//-----------------------------------------------------------------------------
void Init()
{
	game = new Game;
	game->Start();
}
//-----------------------------------------------------------------------------
// Name: �`�揈���B
//-----------------------------------------------------------------------------
VOID Render()
{
	// Turn on the zbuffer
	//g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	//LPDIRECT3DSURFACE9 renderTargetBackup;
	//LPDIRECT3DSURFACE9 depthBufferBackup;
	//g_pd3dDevice->GetRenderTarget(0, &renderTargetBackup);		//���X�̃����_�����O�^�[�Q�b�g��ۑ��B��Ŗ߂��K�v������̂ŁB
	//g_pd3dDevice->GetDepthStencilSurface(&depthBufferBackup);	//���X�̃f�v�X�X�e���V���o�b�t�@��ۑ��B��Ŗ߂��K�v������̂ŁB
	//�I�t�X�N���[�������_�����O�B
	//{
	//	//�����_�����O�^�[�Q�b�g��ύX����B
	//	g_pd3dDevice->SetRenderTarget(0, rendertarget->GetRenderTarget());
	//	g_pd3dDevice->SetDepthStencilSurface(rendertarget->GetDepthStencilBuffer());
		// ��ʂ��N���A�B
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
		//�V�[���̕`��J�n�B
		g_pd3dDevice->BeginScene();
		
		//model��`��B
		game->Render();
	//}
	//g_pd3dDevice->SetRenderTarget(0, renderTargetBackup);		//�߂��B
	//g_pd3dDevice->SetDepthStencilSurface(depthBufferBackup);	//�߂��B
	

	// �V�[���̕`��I���B
	g_pd3dDevice->EndScene();
	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���B
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
/*!-----------------------------------------------------------------------------
*@brief	�X�V�����B
-----------------------------------------------------------------------------*/
void Update()
{
	game->Update();
	//���C�g�̍X�V�B
	UpdateLight();
	
	
}
//-----------------------------------------------------------------------------
//�Q�[�����I������Ƃ��ɌĂ΂�鏈���B
//-----------------------------------------------------------------------------
void Terminate()
{
	game->Terminate();
	delete game;
	
}