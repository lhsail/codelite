#ifndef LLDBBACKTRACE_H
#define LLDBBACKTRACE_H

#include <wx/string.h>
#include <vector>
#include "LLDBSettings.h"

#ifndef __WXMSW__
#   include "lldb/API/SBBlock.h"
#   include "lldb/API/SBCompileUnit.h"
#   include "lldb/API/SBDebugger.h"
#   include "lldb/API/SBFunction.h"
#   include "lldb/API/SBModule.h"
#   include "lldb/API/SBStream.h"
#   include "lldb/API/SBSymbol.h"
#   include "lldb/API/SBTarget.h"
#   include "lldb/API/SBThread.h"
#   include "lldb/API/SBProcess.h"
#   include "lldb/API/SBBreakpoint.h"
#   include "lldb/API/SBListener.h"
#endif

#include "json_node.h"

/**
 * @class LLDBBacktrace
 * Construct a human readable backtrace from lldb::SBThread object
 */
class LLDBBacktrace
{
public:
    struct Entry {
        int      id;
        int      line;
        wxString filename;
        wxString functionName;
        wxString address;
        
        JSONElement ToJSON() const;
        void FromJSON( const JSONElement& json );
        
        Entry() : id(0), line(0) {}
    };
    typedef std::vector<LLDBBacktrace::Entry> EntryVec_t;

protected:
    int m_threadId;
    LLDBBacktrace::EntryVec_t m_callstack;

public:

#ifndef __WXMSW__
    LLDBBacktrace(lldb::SBThread &thread, const LLDBSettings& settings);
#endif

    LLDBBacktrace() : m_threadId (0) {}
    virtual ~LLDBBacktrace();
    
    void Clear() {
        m_threadId = 0;
        m_callstack.clear();
    }
    
    void SetCallstack(const LLDBBacktrace::EntryVec_t& callstack) {
        this->m_callstack = callstack;
    }
    void SetThreadId(int threadId) {
        this->m_threadId = threadId;
    }
    const LLDBBacktrace::EntryVec_t& GetCallstack() const {
        return m_callstack;
    }
    int GetThreadId() const {
        return m_threadId;
    }
    
    wxString ToString() const;
    
    // Serialization API
    JSONElement ToJSON() const;
    void FromJSON( const JSONElement& json );
};

#endif // LLDBBACKTRACE_H