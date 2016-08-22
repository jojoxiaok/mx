// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Decimals.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( TopMargin )

        inline TopMarginPtr makeTopMargin() { return std::make_shared<TopMargin>(); }
		inline TopMarginPtr makeTopMargin( const TenthsValue& value ) { return std::make_shared<TopMargin>( value ); }
		inline TopMarginPtr makeTopMargin( TenthsValue&& value ) { return std::make_shared<TopMargin>( std::move( value ) ); }

        class TopMargin : public ElementInterface
        {
        public:
            TopMargin();
            TopMargin( const TenthsValue& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            TenthsValue getValue() const;
            void setValue( const TenthsValue& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            TenthsValue myValue;
        };
    }
}
