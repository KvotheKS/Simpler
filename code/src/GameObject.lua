GameObject = {
    components = {}, dead = false, started = false
}

GameObject = setmetatable(GameObject,
    {
        __shl = function(tbl, obj)
            tbl[#tbl+1] = obj
            return tbl
        end,

        __shr = function(tbl, obj)
            cnt = #tbl
            for i = 1, cnt do
                if obj == tbl[i] then
                    table.remove(i)
                    return tbl
                end
            end
            return tbl
        end
    }
)

function GameObject:new()
    o = {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function GameObject:Die() self.dead = true end

function GameObject:IsDead() return self.dead end

function GameObject:Update(dt) end

function GameObject:Render() end

function GameObject:Collide(obj) end

function GameObject:Is(game_type) return game_type == "GameObject" end

function GameObject:UpdateComponents(dt)
    cnt = #self.components
    for i = 1, cnt do
        self.components[i]:Update(dt)
        self.components[i]:UpdateComponents(dt)
    end
end

function GameObject:RenderComponents()
    cnt = #self.components
    for i = 1, cnt do
        self.components[i]:Render(dt)
        self.components[i]:RenderComponents(dt)
    end
end