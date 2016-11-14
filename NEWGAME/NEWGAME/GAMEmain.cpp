#include "stdafx.h"
#include "game.h"
#include "RenderTarget.h"

//-----------------------------------------------------------------------------
// グローバル変数。
//-----------------------------------------------------------------------------
Game* game;		
CRenderTarget* rendertarget;
/*!-----------------------------------------------------------------------------
*@brief	ライトを更新。
-----------------------------------------------------------------------------*/
void UpdateLight()
{
	game->UpdateLight();
}
//-----------------------------------------------------------------------------
// Name: ゲームを初期化。
//-----------------------------------------------------------------------------
void Init()
{
	game = new Game;
	game->Start();
}
//-----------------------------------------------------------------------------
// Name: 描画処理。
//-----------------------------------------------------------------------------
VOID Render()
{
	// Turn on the zbuffer
	//g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	//LPDIRECT3DSURFACE9 renderTargetBackup;
	//LPDIRECT3DSURFACE9 depthBufferBackup;
	//g_pd3dDevice->GetRenderTarget(0, &renderTargetBackup);		//元々のレンダリングターゲットを保存。後で戻す必要があるので。
	//g_pd3dDevice->GetDepthStencilSurface(&depthBufferBackup);	//元々のデプスステンシルバッファを保存。後で戻す必要があるので。
	//オフスクリーンレンダリング。
	//{
	//	//レンダリングターゲットを変更する。
	//	g_pd3dDevice->SetRenderTarget(0, rendertarget->GetRenderTarget());
	//	g_pd3dDevice->SetDepthStencilSurface(rendertarget->GetDepthStencilBuffer());
		// 画面をクリア。
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
		//シーンの描画開始。
		g_pd3dDevice->BeginScene();
		
		//modelを描画。
		game->Render();
	//}
	//g_pd3dDevice->SetRenderTarget(0, renderTargetBackup);		//戻す。
	//g_pd3dDevice->SetDepthStencilSurface(depthBufferBackup);	//戻す。
	

	// シーンの描画終了。
	g_pd3dDevice->EndScene();
	// バックバッファとフロントバッファを入れ替える。
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
/*!-----------------------------------------------------------------------------
*@brief	更新処理。
-----------------------------------------------------------------------------*/
void Update()
{
	game->Update();
	//ライトの更新。
	UpdateLight();
	
	
}
//-----------------------------------------------------------------------------
//ゲームが終了するときに呼ばれる処理。
//-----------------------------------------------------------------------------
void Terminate()
{
	game->Terminate();
	delete game;
	
}