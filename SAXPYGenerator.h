#include </home/dharamjeet/data/marg/dharamjeet/scratch/src/sst-elements-library-12.1.0/src/sst/elements/miranda/mirandaGenerator.h>
#include <sst/core/output.h>
#include <sst/core/rng/rng.h>

#include <sst/core/sst_types.h>
#include <sst/core/event.h>
#include <sst/core/component.h>
#include <sst/core/link.h>
#include <sst/core/timeConverter.h>
#include <sst/core/interfaces/simpleMem.h>
//#include generator.h



#include <queue>

using namespace SST::RNG;

namespace SST {
namespace Miranda {

class SAXPYGenerator :  public RequestGenerator {



//(class SAXPYGenerator : public SST::Interfaces::SimpleMem::Handler, public SST::Generator {)

public:

     SAXPYGenerator( ComponentId_t id, Params& params );
        void build(Params& params);
        ~SAXPYGenerator();
        void generate(MirandaRequestQueue<GeneratorRequest*>* q);
        bool isFinished();
        void completed();


    SST_ELI_REGISTER_SUBCOMPONENT(SAXPYGenerator, "miranda", "SAXPYGenerator", SST_ELI_ELEMENT_VERSION(1,0,0),
        "Generates memory accesses for the SAXPY algorithm",
        SST::Miranda::RequestGenerator)
        //(SST::Interfaces::SimpleMem::Handler,SST::Generator)

    SST_ELI_DOCUMENT_PARAMS(
        {"num_elements", "Number of elements in the arrays", "1000000"},
        {"constant_c", "Constant value used in the algorithm", "2.0"}
    )

   // SAXPYGenerator(SST::ComponentId_t id, SST::Params& params);
    //void handleEvent(SST::Interfaces::SimpleMem::Request* ev);

private:
    uint64_t num_elements;
    double constant_c;
    std::vector<double> A, B, Res;
    uint64_t maxAddr;
    Output*  out;


#endif
