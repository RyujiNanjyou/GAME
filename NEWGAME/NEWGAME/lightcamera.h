#pragma once
#include "camera.h"

class Light;

//�Q�[���J����
class LightCamera
{
public:
	LightCamera();
	~LightCamera();
	void Start();//Light* Light
	void Update();
	//�J�������擾�B
	 Camera& GetCamera()
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
	Light*		light;			//�Ǐ]����v���C���[�B
	D3DXVECTOR4 targetOffset;	//�����_�̃I�t�Z�b�g�B
	D3DXVECTOR4 toEyePos;		//�����_���王�_�܂ł̃x�N�g���B	
	D3DXVECTOR3 cameraDir;		//�J�����̕����B
};
