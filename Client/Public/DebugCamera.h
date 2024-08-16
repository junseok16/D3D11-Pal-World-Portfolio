#pragma once
#include "GameObject.h"

namespace Engine
{
	class CCameraComponent;
}

namespace Client
{
	/********************
		Descriptor
	********************/
	struct FDebugCameraDesc : public CGameObject::FGameObjectDesc
	{
		bool m_bUseMouseInput = true;
		bool m_bUseKeyInput = true;
	};

	class CDebugCamera : public CGameObject
	{
	/********************
		Ctor/Dtor
	********************/
	public:
		explicit CDebugCamera() = default;

		virtual ~CDebugCamera() = default;

	/********************
		Events
	********************/
	public:
		static std::shared_ptr<CDebugCamera> Create(const std::shared_ptr<FDebugCameraDesc>& _spDebugCameraDesc);

		virtual HRESULT Initialize(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc) override;

		virtual HRESULT BeginPlay() override;

		virtual int32 PreTick(float _fDeltaSeconds) override;

		virtual int32 Tick(float _fDeltaSeconds) override;
		
		virtual int32 PostTick(float _fDeltaSeconds) override;

		virtual HRESULT EndPlay() override;

		virtual void Release();

	/********************
		Methods
	********************/
	private:
		void InitCameraComponent(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc);

	public:
		HRESULT SetOnAir();

	/********************
		Data Members
	********************/
	private:
		std::shared_ptr<CCameraComponent> m_spCameraComponent;
	};
}
