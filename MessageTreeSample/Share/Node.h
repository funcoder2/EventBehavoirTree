#pragma once
#include "..\Share\EventMessage.h"

namespace BrainTree {

class Node
{
public:
    enum class Status
    {
        Invalid,
        Success,
        Failure,
        Running,
    };

    virtual ~Node() {}

    virtual Status update() = 0;
	virtual Status updateMessage(EventMessage::Ptr message) = 0;
    virtual void initialize() {}
    virtual void terminate(Status s) {}

    Status tick()
    {
        if (status != Status::Running) {
            initialize();
        }

        status = update();

        if (status != Status::Running) {
            terminate(status);
        }

        return status;
    }

	Status onMessage(EventMessage::Ptr message)
	{
		if (status != Status::Running) {
			initialize();
		}

		status = updateMessage(message);

		if (status != Status::Running) {
			terminate(status);
		}

		return status;
	}

    bool isSuccess() const { return status == Status::Success; }
    bool isFailure() const { return status == Status::Failure; }
    bool isRunning() const { return status == Status::Running; }
    bool isTerminated() const { return isSuccess() || isFailure(); }

    void reset() { status = Status::Invalid; }

    using Ptr = std::shared_ptr<Node>;

protected:
    Status status = Status::Invalid;
};

} // BrainTree