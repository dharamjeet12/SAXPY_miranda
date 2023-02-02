#include </home/dharamjeet/data/marg/dharamjeet/scratch/src/sst-elements-library-12.1.0/src/sst/elements/miranda/sst_config.py>
#include <sst/core/params.h>
#include <sst/core/rng/marsaglia.h>
#include </home/dharamjeet/data/marg/dharamjeet/scratch/src/sst-elements-library-12.1.0/src/sst/elements/miranda/SAXPYGenerator.h>

using namespace SST::Miranda;

SAXPYGenerator::SAXPYGenerator( ComponentId_t id, Params& params ) :
        RequestGenerator(id, params) {
            build(params);
        }
void SAXPYGenerator::build(Params& params) {
num_elements = params.find<uint64_t>("num_elements", 1000000);
constant_c = params.find<double>("constant_c", 2.0);

A.resize(num_elements);
B.resize(num_elements);
Res.resize(num_elements);

maxAddr = num_elements * sizeof(double);
out = new Output("SAXPYGenerator[@p:@l]: ", 0, 0, Output::STDOUT);

out->verbose(CALL_INFO, 1, 0, "Number of elements: %" PRIu64 "\n", num_elements);
out->verbose(CALL_INFO, 1, 0, "Constant value: %f\n", constant_c);
}

SAXPYGenerator::~SAXPYGenerator() {
delete out;
}

void SAXPYGenerator::generate(MirandaRequestQueue<GeneratorRequest*>* q) {
out->verbose(CALL_INFO, 4, 0, "Generating next SAXPY operation\n");
for (uint64_t i = 0; i < num_elemenits; i++) {
    // Generate a read request for A[i]
    SimpleMem::Request *req = new SimpleMem::Request(SimpleMem::Request::Read, i*sizeof(double), sizeof(double));
    req->setVirtualAddress(i*sizeof(double));
    q->push_back(req);
}

for (uint64_t i = 0; i < num_elements; i++) {
    // Generate a read request for B[i]
    SimpleMem::Request *req = new SimpleMem::Request(SimpleMem::Request::Read, i*sizeof(double) + maxAddr, sizeof(double));
    req->setVirtualAddress(i*sizeof(double) + maxAddr);
    q->push_back(req);
}

for (uint64_t i = 0; i < num_elements; i++) {
    // Generate a write request for Res[i] = constant_c*A[i] + B[i]
    double val = constant_c*A[i] + B[i];
    SimpleMem::Request *req = new SimpleMem::Request(SimpleMem::Request::Write, i*sizeof(double) + 2*maxAddr, sizeof(double));
    req->setVirtualAddress(i*sizeof(double) + 2*maxAddr);
    req->setDatum(&val);
    std::cout << "Writing to memory address " << i*sizeof(double) + 2*maxAddr << " for Res[" << i << "]" << std::endl;
    q->push_back(req);

}
}

bool SAXPYGenerator::isFinished() {
return false;
}
