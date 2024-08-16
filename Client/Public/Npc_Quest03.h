#pragma once
#include "Npc.h"

namespace Client
{
	class CBowlingSystem;

    class CNpc_Quest03 final : public CNpc
    {
	/********************
		Ctor/Dtor
	********************/
	public:
		explicit CNpc_Quest03() = default;

		virtual ~CNpc_Quest03() = default;

	/********************
		Events
	********************/
	public:
		static shared_ptr<CNpc_Quest03> Create(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc);

		virtual HRESULT Initialize(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc) override;

		virtual HRESULT BeginPlay() override;

		virtual int32 PreTick(float _fDeltaSeconds) override;

		virtual int32 Tick(float _fDeltaSeconds) override;

		virtual int32 PostTick(float _fDeltaSeconds) override;

		virtual HRESULT EndPlay() override;

		virtual void Release() override;

	protected:
		virtual void InitCycle() override;

	/********************
		Getter/Setter
	********************/
	public:

	/********************
		Methods
	********************/
	public:		
		virtual void Interact() override;
	/********************
		Data Members
	********************/
	private:
		std::weak_ptr<CBowlingSystem> m_wpBowlingSystem;

	private:
		bool m_bStartEvent = false;
    };
}

