#include "pch.h"
#include "DebugCamera.h"

#include "CameraComponent.h"

#include "EngineModule.h"
#include "InputManager.h"

std::shared_ptr<CDebugCamera> Client::CDebugCamera::Create(const std::shared_ptr<FDebugCameraDesc>& _spDebugCameraDesc)
{
	const std::shared_ptr<CDebugCamera> spCamera = make_shared<CDebugCamera>();
	ENSUREF(spCamera->Initialize(_spDebugCameraDesc), L"Failed to initialize camera.");
	return spCamera;
}

HRESULT Client::CDebugCamera::Initialize(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc)
{
	if (FAILED(CGameObject::Initialize(_spGameObjectDesc))) { return E_FAIL; }

	InitCameraComponent(_spGameObjectDesc);
	return S_OK;
}

HRESULT Client::CDebugCamera::BeginPlay()
{
	if (FAILED(CGameObject::BeginPlay())) { return E_FAIL; }

	return S_OK;
}

int32 Client::CDebugCamera::PreTick(float _fDeltaSeconds)
{
	switch (CGameObject::PreTick(_fDeltaSeconds))
	{
	case -1:	return -1;
	default:	break;
	}

	if (CEngineModule::GetInstance()->GetInputManager()->IsKeyDown(DIK_NUMPAD1))
	{
		SetOnAir();
	}

	return S_OK;
}

int32 Client::CDebugCamera::Tick(float _fDeltaSeconds)
{
	switch (CGameObject::Tick(_fDeltaSeconds))
	{
	case -1:	return -1;
	default:	break;
	}

	return S_OK;
}

int32 Client::CDebugCamera::PostTick(float _fDeltaSeconds)
{
	switch (CGameObject::PostTick(_fDeltaSeconds))
	{
	case -1:	return -1;
	default:	break;
	}

	return S_OK;
}

HRESULT Client::CDebugCamera::EndPlay()
{
	if (FAILED(CGameObject::EndPlay())) { return E_FAIL; }

	return S_OK;
}

void Client::CDebugCamera::Release()
{
	m_spCameraComponent = nullptr;

	CGameObject::Release();
}

void Client::CDebugCamera::InitCameraComponent(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc)
{
	std::shared_ptr<FDebugCameraDesc> spCameraDesc = static_pointer_cast<FDebugCameraDesc>(_spGameObjectDesc);

	// component desc
	std::shared_ptr<FCameraComponentDesc> spCameraComponentDesc = make_shared<FCameraComponentDesc>();

	spCameraComponentDesc->m_wpOwnerGameObject		= shared_from_this();
	spCameraComponentDesc->m_eComponentType			= EComponentType::CAMERA;
	spCameraComponentDesc->m_wstrComponentName		= L"DebugCameraComponent";
	spCameraComponentDesc->m_eRenderType			= ERenderType::NONE;

	// camera component desc
	spCameraComponentDesc->m_eCameraType			= ECameraType::DEBUG_;
	spCameraComponentDesc->m_bMouseControl			= spCameraDesc->m_bUseMouseInput;
	spCameraComponentDesc->m_bKeyboardControl		= spCameraDesc->m_bUseKeyInput;
	spCameraComponentDesc->m_fMouseSensitivity		= 0.1f;
	spCameraComponentDesc->m_fKeyboardSensitivity	= 3.0f;

	spCameraComponentDesc->m_eProjectionType			= EProjectionType::PERSPECTIVE;
	spCameraComponentDesc->m_fAspectRatio			= 16.0f / 9.0f;
	spCameraComponentDesc->m_fFieldOfView			= 60.0f;
	spCameraComponentDesc->m_fFarPlane				= 5000.0f;
	spCameraComponentDesc->m_fNearPlane				= 0.1f;

	spCameraComponentDesc->m_vSphericalCameraAxisOffset = Vector3(0.0f);
	spCameraComponentDesc->m_vSphericalCameraEyeOffset	= Vector3(0.0f);
	spCameraComponentDesc->m_fCurSphericalCameraRadius	= 5.0f;
	spCameraComponentDesc->m_fMinElevationDegree		= 0.0f;
	spCameraComponentDesc->m_fMaxElevationDegree		= 60.0f;

	spCameraComponentDesc->m_fCullFrustumNear			= 0.1f;
	spCameraComponentDesc->m_fCullFrustumFar			= 100.0f;

	shared_ptr<CCameraComponent> spCameraComponent = CCameraComponent::Create(spCameraComponentDesc);
	AddComponent(spCameraComponentDesc->m_wstrComponentName, spCameraComponent);
	m_spCameraComponent = spCameraComponent;
}

HRESULT Client::CDebugCamera::SetOnAir()
{
	return m_spCameraComponent->SetOnAir();
}
