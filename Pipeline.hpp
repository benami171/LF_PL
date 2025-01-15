#include <vector>
#include <pthread.h>
#include "ActiveObject.hpp"
#include "Algo.hpp"
#include "Graph.hpp"

#pragma once

using namespace std;

class Pipeline{
    // list to hold all pipeline threads id and args
    std::vector<pthread_t> workers; 
    // cond if worker is finished
    pthread_cond_t condWorker;
    // mutex to add worker to list
    pthread_mutex_t mutexWorker;
    // head of active objects list
    ActiveObject* _stage;
    
    bool _isRunning;                          

    
public:
    // constructor pipeline, gets a mst algo function
    Pipeline(pair<int,Graph> (*mstAlgo) (int, Graph));
    // virtual distructor for inherited class
    virtual ~Pipeline();
    // create threads of pipeline
    void execute();

    void stop();
    // add Task to head of active objects
    void addTask(int fd, Graph graph);
    // function that runs in thread
    static void* runStage(void* stage);
    // kill all workers from thread list
    static void destroyAll();
};

// create Prim and Kruskal Pipelines inherit from Pipeline
class PipelinePrim: public Pipeline{

public:
    PipelinePrim(): Pipeline(MSTAlgo::Prim){};
    ~PipelinePrim() override {};
};


class PipelineKruskal: public Pipeline{

public:
    PipelineKruskal(): Pipeline(MSTAlgo::Kruskal){};
    ~PipelineKruskal() override {};
};

class FactoryPipeline{
public:
    // function that gets an instance of pipeline from algo string
    static Pipeline* get(string algo){
        if (algo=="Prim"){
            PipelinePrim* g = Singletone<PipelinePrim>::getInstance();
            return static_cast<Pipeline*>(g);
        }
        else if(algo == "Kruskal"){
            PipelineKruskal* g = Singletone<PipelineKruskal>::getInstance();
            return static_cast<Pipeline*>(g);
        }
        else{
            throw invalid_argument("Algorithm not supported!");
        }
    }
};