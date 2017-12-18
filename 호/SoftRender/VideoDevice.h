#pragma once





//	1. Position 정점의 좌표 x,y,z(float)            : D3DFVF_XYZ
// 	2. RHW (float)                                  : D3DFVF_XYZRHW (D3DFVF_XYZ 또는 D3DFVF_NORMAL과 같이 사용불가)
// 	3. Blending Weight Data 결합 가중치 (float)		: D3DFVF_XYZB1 ~ D3DFVF_XYZB5
// 	4. Vertex Normal 정점의 법선 벡터 x,y,z(float)	: D3DFVF_NORMAL
// 	5. Vertex Point Size 정점의 점 크기 (float)		: D3DFVF_PSIZE
// 	6. Diffuse Color (DWORD)						: D3DFVF_DIFFUSE
// 	7. Specular Color (DWORD)						: D3DFVF_SPECULAR
// 	8. Texture Coordinate Set 1 (float)             : D3DFVF_TEX0 - D3DFVF_TEX8


class VideoDevice
{
	SINGLETON( VideoDevice )

	void Init();
	void RenderBegin();
	void RenderEnd();

	void Destroy();

	LPDIRECT3DDEVICE9 GetDevice();

private:
	LPDIRECT3D9 d3d9;
	LPDIRECT3DDEVICE9 d3dDevice9;

	VertexPC	vertexPCs[3];
	std::vector<VertexPC> vertexPCList;

	VertexPT	vertexPTs[3];

	// 텍스쳐 테스트
	LPDIRECT3DTEXTURE9 texture;
	D3DXMATRIXA16 worldMatrix;


};


#define D3DDevice VideoDevice::GetInstance()->GetDevice()
