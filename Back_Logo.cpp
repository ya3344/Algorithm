#include "stdafx.h"
#include "..\Headers\Back_Logo.h"
#include "Component_Manager.h"

_USING(Client)

CBack_Logo::CBack_Logo(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CGameObject(pGraphic_Device)
{

}

CBack_Logo::CBack_Logo(const CBack_Logo & rhs)
	: CGameObject(rhs)
{
}

HRESULT CBack_Logo::Ready_GameObject_Prototype()
{
	// 실제 원형 객체를 생성하기 위한 작업을 수행한다.
	// ex> 파일입출력을 통한 데이터 셋

	return NOERROR;
}

HRESULT CBack_Logo::Ready_GameObject()
{
	// 이 객체에 필요한 컴포넌트를 추가하자.
	if(FAILED(Ready_Component()))
		return E_FAIL;

	return NOERROR;
}

_int CBack_Logo::Update_GameObject(const _float & fTimeDelta)
{
	return _int();
}

_int CBack_Logo::LastUpdate_GameObject(const _float & fTimeDelta)
{
	if(nullptr == m_pRendererCom)
		return -1;

	if(1)
	{
		if(FAILED(m_pRendererCom->Add_RenderGroup(CRenderer::RENDER_NONALPHA, this)))
			return -1;
	}
	

	return _int();
}

void CBack_Logo::Render_GameObject()
{
	if(nullptr == m_pRendererCom
		|| nullptr == m_pBufferCom)
		return;


	LPD3DXEFFECT pEffect = m_pShaderCom->Get_EffectHandle();
	if(nullptr == pEffect)
		return;

	_matrix			matTmp;
	D3DXMatrixIdentity(&matTmp);

	pEffect->SetMatrix("g_matWorld", &matTmp);
	pEffect->SetMatrix("g_matView", &matTmp);
	pEffect->SetMatrix("g_matProj", &matTmp);

	m_pTextureCom->SetUp_OnShader(pEffect, "g_BaseTexture", 0);

	pEffect->Begin(nullptr, 0);	
	pEffect->BeginPass(0);

	m_pBufferCom->Render_Buffer();

	pEffect->EndPass();
	pEffect->End();


}

HRESULT CBack_Logo::Ready_Component(void)
{
	CComponent*		pComponent = nullptr;

	// For.Com_Transform
	pComponent = m_pTransCom = (CTransform*)CComponent_Manager::GetInstance()->Clone_Component(SCENE_STATIC, L"Component_Transform");
	if(nullptr == pComponent)
		return E_FAIL;	
	if(FAILED(CGameObject::Add_Component(L"Com_Transform", pComponent)))
		return E_FAIL;

	// For.Com_Renderer
	pComponent = m_pRendererCom = (CRenderer*)CComponent_Manager::GetInstance()->Clone_Component(SCENE_STATIC, L"Component_Renderer");
	if(nullptr == pComponent)
		return E_FAIL;
	if(FAILED(CGameObject::Add_Component(L"Com_Renderer", pComponent)))
		return E_FAIL;

	// For.Com_Buffer
	pComponent = m_pBufferCom = (CRect_Texture*)CComponent_Manager::GetInstance()->Clone_Component(SCENE_STATIC, L"Component_Buffer_RectTexture");
	if(nullptr == pComponent)
		return E_FAIL;
	if(FAILED(CGameObject::Add_Component(L"Com_Buffer", pComponent)))
		return E_FAIL;

	// For.Com_Shader
	pComponent = m_pShaderCom = (CShader*)CComponent_Manager::GetInstance()->Clone_Component(SCENE_STATIC, L"Component_Shader_Default");
	if(nullptr == pComponent)
		return E_FAIL;
	if(FAILED(CGameObject::Add_Component(L"Com_Shader", pComponent)))
		return E_FAIL;

	// For.Com_Texture
	pComponent = m_pTextureCom = (CTexture*)CComponent_Manager::GetInstance()->Clone_Component(SCENE_STATIC, L"Component_Texture_Logo");
	if(nullptr == pComponent)
		return E_FAIL;
	if(FAILED(CGameObject::Add_Component(L"Com_Texture", pComponent)))
		return E_FAIL;

	return NOERROR;
}

CBack_Logo * CBack_Logo::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CBack_Logo*	pInstance = new CBack_Logo(pGraphic_Device);

	if(FAILED(pInstance->Ready_GameObject_Prototype()))
	{
		_MSG_BOX("CBack_Logo Created Failed");
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject * CBack_Logo::Clone(void)
{
	CBack_Logo*	pInstance = new CBack_Logo(*this);

	if(FAILED(pInstance->Ready_GameObject()))
	{
		_MSG_BOX("CBack_Logo Created Failed");
		Safe_Release(pInstance);
	}

	return pInstance;
}

_ulong CBack_Logo::Free(void)
{
	Safe_Release(m_pTransCom);
	Safe_Release(m_pRendererCom);
	Safe_Release(m_pBufferCom);
	Safe_Release(m_pShaderCom);
	Safe_Release(m_pTextureCom);

	CGameObject::Free();

	return _ulong();
}
