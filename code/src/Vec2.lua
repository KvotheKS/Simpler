Vec2 = {
    0,0,
    new = function(self, x, y)
        o = {}
        z = (y and {x,y}) or x or {0,0}
        setmetatable(o, self)
        self.__index = self
        o[1],o[2] = z[1],z[2]
        return o
    end,

    __add = function(vec1, vec2)
        vec1[1] = vec1[1] + vec2[1]
        vec1[2] = vec1[2] + vec2[2]
        return vec1
    end,
    
    __sub = function(vec1, vec2)
        vec1[1] = vec1[1] - vec2[1]
        vec1[2] = vec1[2] - vec2[2]
        return vec1
    end,
    
    __mul = function(vec1, vec2)
        vec2 = (type(vec2) == 'table' and vec2) or {vec2, vec2}
        vec1[1] = vec1[1] * vec2[1]
        vec1[2] = vec1[2] * vec2[2]
        return vec1    
    end,
    
    __div = function(vec1, vec2)
        vec2 = (type(vec2) == 'table' and vec2) or {vec2, vec2}
        vec1[1] = vec1[1] / vec2[1]
        vec1[2] = vec1[2] / vec2[2]
        return vec1
    end,

    mag = function(self) return math.sqrt(self[1] * self[1] + self[2] * self[2]) end,
    
    norm = function(self) return Vec2:new(self) / self:mag() end,
    
    dist = function(self, vec) 
        local xl, yl = self[1] - vec[1], self[2]- vec[2]
        return math.sqrt(xl*xl + yl*yl)
    end,
    
    theta = function(self)
        return math.atan2(self[2], self[1])
    end
}
Vec2 = setmetatable(Vec2, Vec2)