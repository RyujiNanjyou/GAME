#pragma once
#include "camera.h"

class Unity;

//�Q�[���J����
class PlayerCamera
{
public:
	PlayerCamera();
	~PlayerCamera();
	void Start(Unity* uni);
	void PreUpdate();
	void Update();
	//�J�������擾�B
	const Camera& GetCamera() const
	{
		return camera;
	}
	//�J�����̕������擾�B
	D3DXVECTOR3 GetCameraDir() const
	{
		return cameraDir;
	}

private:
	//�J�������X�V�B
	void UpdateCamera();
	Camera		camera;
	Unity*		uni;			//�Ǐ]����v���C���[�B
	D3DXVECTOR4 targetOffset;	//�����_�̃I�t�Z�b�g�B
	D3DXVECTOR4 toEyePos;		//�����_���王�_�܂ł̃x�N�g���B	
	D3DXVECTOR3 cameraDir;		//�J�����̕����B
};

