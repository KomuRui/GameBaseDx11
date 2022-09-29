#include "Image.h"
#include "SceneManager.h"
#include "Input.h"
#include "ImGuiSet.h"
#include "Model.h"
#include "SphereCollider.h"
#include "../Player.h"
#include "..\imgui\\imgui.h"
#include "..\imgui\\imgui_impl_win32.h"
#include "..\imgui\\imgui_impl_dx11.h"

//�R���X�g���N�^
ImGuiSet::ImGuiSet(GameObject* parent)
	: GameObject(parent, "ImGuiSet"), Create3Dflag(false), ObjectCount(0)
{
}

//������
void ImGuiSet::Initialize()
{
}

//�X�V
void ImGuiSet::Update()
{
}

//�`��
void ImGuiSet::Draw()
{
    //Imgui�X�^�[�g
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    //window���
    ImGui::Begin("PlayerPosition");

    Player* pPlayer = (Player*)FindObject("Player");
    XMFLOAT3 pos = { pPlayer->GetPosition().x,pPlayer->GetPosition().y,pPlayer->GetPosition().z };

    ImGui::Text("x");
    ImGui::InputFloat("x", &pos.x, -2000000.0f, 2000000.0f);
    ImGui::Text("y");
    ImGui::InputFloat("y", &pos.y, -2000000.0f, 2000000.0f);
    ImGui::Text("z");
    ImGui::InputFloat("z", &pos.z, -2000000.0f, 2000000.0f);

    //3D�����{�^��
    if (ImGui::Button("Create3D"))
    {
        Create3Dflag = true;
        ObjectCount++;
    }

    //�J�����{�^��
    if (ImGui::Button("Camera"))
    {
    }

    //flag��true�Ȃ�֐����Ăяo��
    if (Create3Dflag)
    {
        Create3D();
    }

    ImGui::End();

    ImGui::Render();
    //�`��
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiSet::Create3D()
{
    //�e�I�u�W�F�N�g�̏��
    static int status[MAX_OBJECT_SIZE] = {};

    //Create3D�����������E�B���h�E�����
    for (int i = 0; i < ObjectCount; i++)
    {
        if (status[i] == 1 || status[i] == 0)
        {
            //i��FBX�̌��ɂ���
            char name[16];
            sprintf_s(name, "FBX %d", i);

            //window���
            ImGui::Begin(name);

            //�t�@�C���l�[�����͗�
            static char text1[MAX_OBJECT_SIZE][50] = {};

            //���͂��ꂽ������text1�Ɋi�[
            ImGui::InputText("FBX filename", text1[i], sizeof(text1[i]));

            //���[�h�{�^��
            if (ImGui::Button("Load"))
            {
                //�����܂��������[�h���ĂȂ�������
                if (status[i] == 0)
                {
                    Player* pPlayer = (Player*)FindObject("Player");

                    //���[�h�����I�u�W�F�N�g�ɕK�v�ȃg�����X�t�H�[����p��
                    Transform t;
                    t.position_ = pPlayer->GetPosition();

                    //�v�b�V�����邽�߂�pair�^�����
                    //first->���[�h�������f���ԍ�
                    //second->���[�h�������f����transform
                    std::pair<int, Transform> a(Model::Load(text1[i]), t);
                    assert(a.first < 0);

                    //vector�Ɋi�[����
                    obj.push_back(a);

                    //status�v���X
                    status[i]++;
                }
            }

            //��񃍁[�h���Ă�����
            if (status[i] == 1)
            {
                SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
                static XMFLOAT3 pos = { 0,0,0 };
                static XMFLOAT3 pos2 = { 0,0,0 };

                //Position�̖�
                if (ImGui::TreeNode("position")) {

                    //Position�Z�b�g
                    ImGui::SliderFloat("x", &obj[i].second.position_.x, -20.0f, 20.0f);
                    ImGui::SliderFloat("y", &obj[i].second.position_.y, -20.0f, 20.0f);
                    ImGui::SliderFloat("z", &obj[i].second.position_.z, -20.0f, 20.0f);

                    ImGui::TreePop();
                }

                //Scale�̖�
                if (ImGui::TreeNode("scale")) {

                    //Scale�Z�b�g
                    ImGui::SliderFloat("x", &obj[i].second.scale_.x, -20.0f, 20.0f);
                    ImGui::SliderFloat("y", &obj[i].second.scale_.y, -20.0f, 20.0f);
                    ImGui::SliderFloat("z", &obj[i].second.scale_.z, -20.0f, 20.0f);

                    ImGui::TreePop();
                }

                //rotate�̖�
                if (ImGui::TreeNode("rotate")) {

                    //Rotate�Z�b�g
                    ImGui::SliderFloat("x", &obj[i].second.rotate_.x, 0.0f, 360.0f);
                    ImGui::SliderFloat("y", &obj[i].second.rotate_.y, 0.0f, 360.0f);
                    ImGui::SliderFloat("z", &obj[i].second.rotate_.z, 0.0f, 360.0f);

                    ImGui::TreePop();
                }

                if (ImGui::Button("Collsion"))
                {
                    AddCollider(collision);
                }

                //�����蔻��̒ǉ�
                if (ImGui::TreeNode("CollisionPos")) {

                    ImGui::SliderFloat("x", &pos.x, -20.0f, 20.0f);
                    ImGui::SliderFloat("y", &pos.y, -20.0f, 20.0f);
                    ImGui::SliderFloat("z", &pos.z, -20.0f, 20.0f);

                    if (ImGui::TreeNode("InputCollisionPos")) {

                        ImGui::Text("x");
                        ImGui::InputFloat("x", &pos2.x, -20.0f, 20.0f);
                        ImGui::Text("y");
                        ImGui::InputFloat("y", &pos2.y, -20.0f, 20.0f);
                        ImGui::Text("z");
                        ImGui::InputFloat("z", &pos2.z, -20.0f, 20.0f);

                        if (ImGui::Button("Save"))
                        pos = pos2;

                        ImGui::TreePop();
                    }

                    if (collision->GetColliderPos().x != pos.x || collision->GetColliderPos().y != pos.y || collision->GetColliderPos().z != pos.z)
                    {
                        collision->SetColliderPos(pos);
                        KillCollider(collision);
                        SphereCollider* collision = new SphereCollider(XMFLOAT3(pos), 1.2f);
                        AddCollider(collision);
                    }

                 
                    ImGui::TreePop();
                }

                //�E�B���h�E�폜
                if (ImGui::Button("close"))
                {
                    status[i]++;
                }
            }

            ImGui::End();
        }

        //�`�悳���
        if (status[i] >= 1)
        {
            //�`��
            Model::Draw(obj[i].first);
            Model::SetTransform(obj[i].first, obj[i].second);
        }
    }
}

//�J��
void ImGuiSet::Release()
{
}

