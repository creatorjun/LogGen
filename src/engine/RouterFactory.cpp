// src/engine/RouterFactory.cpp
#include "RouterFactory.h"
#include "NexGfwRouter.h"
#include "VirusTotalRouter.h"
#include "SpamhausRouter.h"
#include "SecuiRouter.h"
#include "FortinetRouter.h"
#include "Mf2Router.h"
#include "WinsTaxiiRouter.h"
#include <vector>
#include <memory>

std::unique_ptr<ApiRouter> RouterFactory::create() {
    auto nexgfw     = std::make_unique<NexGfwRouter>();
    auto virustotal = std::make_unique<VirusTotalRouter>();
    auto spamhaus   = std::make_unique<SpamhausRouter>();
    auto secui      = std::make_unique<SecuiRouter>();
    auto fortinet   = std::make_unique<FortinetRouter>();
    auto mf2        = std::make_unique<Mf2Router>();
    auto winsTaxii  = std::make_unique<WinsTaxiiRouter>();

    NexGfwRouter*     pNexgfw     = nexgfw.get();
    VirusTotalRouter* pVirustotal = virustotal.get();
    SpamhausRouter*   pSpamhaus   = spamhaus.get();
    SecuiRouter*      pSecui      = secui.get();
    FortinetRouter*   pFortinet   = fortinet.get();
    Mf2Router*        pMf2        = mf2.get();
    WinsTaxiiRouter*  pWinsTaxii  = winsTaxii.get();

    std::vector<std::unique_ptr<ISubRouter>> subRouters;
    subRouters.push_back(std::move(nexgfw));
    subRouters.push_back(std::move(virustotal));
    subRouters.push_back(std::move(spamhaus));
    subRouters.push_back(std::move(secui));
    subRouters.push_back(std::move(fortinet));
    subRouters.push_back(std::move(mf2));
    subRouters.push_back(std::move(winsTaxii));

    std::vector<ApiRouter::PrefixEntry> prefixMap = {
        { "/nexgfw/",     pNexgfw     },
        { "/vtapi/",      pVirustotal },
        { "/spamhaus/",   pSpamhaus   },
        { "/secui/",      pSecui      },
        { "/api/v2/",     pFortinet   },
        { "/logincheck",  pFortinet   },
        { "/logout",      pFortinet   },
        { "/fortinet/",   pFortinet   },
        { "/mf2/",        pMf2        },
        { "/api/taxii2/", pWinsTaxii  },
        { "/wins/",       pWinsTaxii  },
    };

    return std::make_unique<ApiRouter>(std::move(subRouters), std::move(prefixMap));
}
