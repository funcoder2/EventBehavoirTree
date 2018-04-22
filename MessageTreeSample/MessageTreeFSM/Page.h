#pragma once
#include "stdafx.h"

class PageFSM;

class Page {
public:
	using Ptr = std::shared_ptr<Page>;

public:
	Page(int pageId, PageFSM* owner);
	~Page();

public:
	/// ���� �������̽�
	// ����
	void onStart();
	// �ֱ� ������Ʈ
	void onUpdate();
	// ����
	void onEnd();
	// �޽���
	void onMessage(EventMessage::Ptr message);

public:
	/// ���� ������
	// ���� BT�� �����.
	void makeSample();

public:
	/// Getter/Setter
	int getPageId() const { return pageId_; }
	void setRoot(const BrainTree::Node::Ptr &node);
	PageFSM* getOwner() const { return owner_; }

private:
	int pageId_ = 0;
	PageFSM* owner_ = nullptr;
	BrainTree::BehaviorTree behaviorTree_;
};